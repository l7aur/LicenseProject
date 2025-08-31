#include "ExecutionPipeline.hpp"
#include "IFilter.hpp"

#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>

#include <variant>

ExecutionPipeline::ExecutionPipeline(const std::filesystem::path seriesPath_)
	: seriesPath{ seriesPath_ } 
{
	for (const auto& entry : std::filesystem::directory_iterator(seriesPath))
		if (entry.is_regular_file())
			paths.push_back(entry.path());
	wspaces.resize(paths.size());
}

void ExecutionPipeline::addFilter(std::unique_ptr<IFilter> newFilter)
{
	if(newFilter)
		filters.push_back(std::move(newFilter));
}

void ExecutionPipeline::executeWithCaching()
{
	for (const auto& currentFilter : filters) {
		//loadInput(prevFilter);
		currentFilter->execute(paths, wspaces);
		cache(currentFilter->getCachePath());
	}
}

void ExecutionPipeline::execute()
{
	for (const auto& currentFilter : filters)
		currentFilter->execute(paths, wspaces);
}

void ExecutionPipeline::display() const
{
	if (wspaces.empty())
		return;
	if (!std::holds_alternative<Slice>(*wspaces.at(0)))
		return;
	for (int i = 0; i < wspaces.size(); ++i) {
		Slice& s = std::get<Slice>(*wspaces.at(i));
		cv::Mat m{
			static_cast<int>(s.getHeight()),
			static_cast<int>(s.getWidth()),
			CV_8UC1,
			s.getPixels()
		};
		cv::imshow("image" + std::to_string(i + 1), m);
		cv::waitKey(0);
	}
}

void ExecutionPipeline::cache(const std::string_view& cachePath) const
{
	for (const auto& wspace : wspaces)
		std::visit([&cachePath](const auto& w) { w.serialize(cachePath); }, *wspace);
}
