#include "PixelExtractor.hpp"
#include "Slice.hpp"
#include <filesystem>
#include <stdexcept>

PixelExtractor::~PixelExtractor()
{
	for (const auto& slice : series)
		delete slice;
}

void PixelExtractor::setup(const std::string& workingDirectoryPath)
{
	this->workingDirectoryPath = workingDirectoryPath;
}

void PixelExtractor::execute() const {
	size_t index = 0;
	/*for (const auto& entry : std::filesystem::directory_iterator(workingDirectoryPath))
		if (entry.is_regular_file()) {
			this->submit(
				[index, filePath = entry.path().string(), this] {
					this->series.at(index) = new Slice(filePath);
				});
			index++;
		}*/
}

void PixelExtractor::saveProgress(const std::string& checkpointPath) const {

}

bool PixelExtractor::existsCheckpoint() const {
	return true;
}

void PixelExtractor::loadCheckpoint(const std::string& checkpointPath) {

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
	if (std::filesystem::exists(CHECKPOINT_PATH))
		std::filesystem::remove_all(CHECKPOINT_PATH);
	if (!std::filesystem::create_directories(CHECKPOINT_PATH))
		throw std::exception("Unable to create directories for checkpoint!");

	size_t index = 0;
	for (const auto& entry : std::filesystem::directory_iterator(path))
		if (entry.is_regular_file()) {
			this->submit(
				[index, filePath = entry.path().string(), this] {
					this->series.at(index) = new Slice(filePath);
					this->series.at(index)->saveCheckpoint(CHECKPOINT_PATH);
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