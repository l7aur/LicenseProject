#include "ExecutionPipeline.hpp"
#include "IFilter.hpp"

#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>

#include <variant>

ExecutionPipeline::ExecutionPipeline(const std::filesystem::path dir)
	: directory{ dir } 
{
	for (const auto& entry : std::filesystem::directory_iterator(directory))
		if (entry.is_regular_file())
			paths.push_back(entry.path());
	wspace.resize(paths.size());
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
		currentFilter->execute(paths, wspace);
		//saveProgress("/checkpointPath");
	}
}

void ExecutionPipeline::execute()
{
	for (const auto& currentFilter : filters)
		currentFilter->execute(paths, wspace);
}

void ExecutionPipeline::display() const
{
	for (int i = 0; i < wspace.size(); ++i) {
		Slice& s = std::get<Slice>(*wspace.at(i));
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
