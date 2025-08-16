#include "PixelExtractor.hpp"
#include "Slice.hpp"

#include <filesystem>
#include <stdexcept>

PixelExtractor::PixelExtractor()
{
	workingDirectory = "./checkpoint/preprocessing/";
}

void PixelExtractor::execute(std::vector<std::pair<std::filesystem::path, std::unique_ptr<Slice>>>& wspace) {
	for (size_t i = 0; i < wspace.size(); ++i)
		submit([&wspace, i]() { wspace[i].second = std::make_unique<Slice>(wspace[i].first); });
	waitForFinish();
}


void PixelExtractor::saveProgress(const std::string& checkpointPath) const {

}

bool PixelExtractor::existsCheckpoint() const {
	return true;
}

void PixelExtractor::loadInput(IFilter* const prevFilter) {
	if (prevFilter == nullptr)
		return;
}

void PixelExtractor::setupSeries(const std::string& path)
{
	size_t numberOfFiles = 0;
	for (const auto& entry : std::filesystem::directory_iterator(path))
		if (entry.is_regular_file())
			numberOfFiles++;
	//series.resize(numberOfFiles, nullptr);
}

void PixelExtractor::populateSeriesWithCheckpoint(const std::string& path)
{
	if (std::filesystem::exists(workingDirectory))
		std::filesystem::remove_all(workingDirectory);
	if (!std::filesystem::create_directories(workingDirectory))
		throw std::exception("Unable to create directories for checkpoint!");

	/*size_t index = 0;
	for (const auto& entry : std::filesystem::directory_iterator(path))
		if (entry.is_regular_file()) {
			this->submit(
				[index, filePath = entry.path().string(), this] {
					this->series.at(index) = new Slice(filePath);
					this->series.at(index)->saveCheckpoint(workingDirectory);
				});
			index++;
		}*/
}

void PixelExtractor::populateSeriesWithoutCheckpoint(const std::string& path)
{
	/*size_t index = 0;
	for (const auto& entry : std::filesystem::directory_iterator(path))
		if (entry.is_regular_file()) {
			this->submit(
				[index, filePath = entry.path().string(), this] {
					this->series.at(index) = new Slice(filePath);
				});
			index++;
		}*/
}