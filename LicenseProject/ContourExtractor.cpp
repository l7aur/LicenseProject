#include "ContourExtractor.hpp"
#include "LocalThresholder.hpp"

ContourExtractor::ContourExtractor()
{
	workingDirectory = "./checkpoint/contour_extractor/";
}

void ContourExtractor::execute(const std::vector<std::filesystem::path>& paths, workspace& wspace)
{
	for (size_t i = 0; i < wspace.size(); ++i)
		submit(LocalThresholder::execute(wspace, i));
	waitForFinish();
}
