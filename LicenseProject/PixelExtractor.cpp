#include "PixelExtractor.hpp"
#include "Slice.hpp"

#include <filesystem>
#include <stdexcept>

PixelExtractor::PixelExtractor()
{
	workingDirectory = "./checkpoint/pixel_extractor/";
}

void PixelExtractor::execute(std::vector<std::pair<std::filesystem::path, std::unique_ptr<Slice>>>& wspace) {
	for (size_t i = 0; i < wspace.size(); ++i)
		submit([&wspace, i]() { wspace[i].second = std::make_unique<Slice>(wspace[i].first); });
	waitForFinish();
}