#include "PointExtractorFilter.hpp"

PointExtractorFilter::PointExtractorFilter(const std::string_view& cachePath_)
{
	cachePath = cachePath_;
}

void PointExtractorFilter::execute(const std::vector<std::filesystem::path>& paths, workspace& wspace)
{
}
