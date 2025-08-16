#include "ContourExtractor.hpp"
#include "LocalThresholder.hpp"

ContourExtractor::ContourExtractor()
{
	workingDirectory = "./checkpoint/contour_extractor/";
}

void ContourExtractor::execute(std::vector<std::pair<std::filesystem::path, std::unique_ptr<Slice>>>& wspace)
{
	for (size_t i = 0; i < wspace.size(); ++i)
		submit(LocalThresholder::execute(wspace, i));
	waitForFinish();
}
