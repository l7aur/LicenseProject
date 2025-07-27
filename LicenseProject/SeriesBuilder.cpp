#include "SeriesBuilder.hpp"
#include "Slice.hpp"
#include <filesystem>
#include <stdexcept>

SeriesBuilder::SeriesBuilder(const std::string& path, const bool createCheckpoint) {
	if(!std::filesystem::exists(path))
		throw std::exception("Path to the folder does not exist!");
	setupSeries(path);
	createCheckpoint
		? populateSeriesWithCheckpoint(path)
		: populateSeriesWithoutCheckpoint(path);
}

SeriesBuilder::~SeriesBuilder()
{
	for (const auto& slice : series)
		delete slice;
}

void SeriesBuilder::setupSeries(const std::string& path)
{
	size_t numberOfFiles = 0;
	for (const auto& entry : std::filesystem::directory_iterator(path))
		if (entry.is_regular_file())
			numberOfFiles++;
	series.resize(numberOfFiles, nullptr);
}

void SeriesBuilder::populateSeriesWithCheckpoint(const std::string& path)
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

void SeriesBuilder::populateSeriesWithoutCheckpoint(const std::string& path)
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