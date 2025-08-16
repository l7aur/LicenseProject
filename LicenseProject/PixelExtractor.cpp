#include "PixelExtractor.hpp"
#include "Slice.hpp"
#include "matrix.hpp"

#include <filesystem>
#include <stdexcept>

PixelExtractor::PixelExtractor()
{
	workingDirectory = "./checkpoint/preprocessing/";
}

PixelExtractor::~PixelExtractor()
{
	for (const auto& slice : series)
		delete slice;
}

void PixelExtractor::execute(const std::map<std::filesystem::path, matrix<Settings::pixel>>& paths) const {
	/*for (size_t i = 0; i < paths.size(); ++i)
		this->submit([i, filePath = paths.at(i), matrices]
			{ Slice::process(i, filePath, matrices); 
		});*/
}

void PixelExtractor::saveProgress(const std::string& checkpointPath) const {

}

bool PixelExtractor::existsCheckpoint() const {
	return true;
}

void PixelExtractor::loadInput(IFilter* const prevFilter) {

}

void PixelExtractor::loadInput(const std::filesystem::path& checkpoint)
{
}

void PixelExtractor::setupSeries(const std::string& path)
{
	size_t numberOfFiles = 0;
	for (const auto& entry : std::filesystem::directory_iterator(path))
		if (entry.is_regular_file())
			numberOfFiles++;
	series.resize(numberOfFiles, nullptr);
}

void PixelExtractor::populateSeriesWithCheckpoint(const std::string& path)
{
	if (std::filesystem::exists(workingDirectory))
		std::filesystem::remove_all(workingDirectory);
	if (!std::filesystem::create_directories(workingDirectory))
		throw std::exception("Unable to create directories for checkpoint!");

	size_t index = 0;
	for (const auto& entry : std::filesystem::directory_iterator(path))
		if (entry.is_regular_file()) {
			this->submit(
				[index, filePath = entry.path().string(), this] {
					this->series.at(index) = new Slice(filePath);
					this->series.at(index)->saveCheckpoint(workingDirectory);
				});
			index++;
		}
}

void PixelExtractor::populateSeriesWithoutCheckpoint(const std::string& path)
{
	size_t index = 0;
	for (const auto& entry : std::filesystem::directory_iterator(path))
		if (entry.is_regular_file()) {
			this->submit(
				[index, filePath = entry.path().string(), this] {
					this->series.at(index) = new Slice(filePath);
				});
			index++;
		}
}