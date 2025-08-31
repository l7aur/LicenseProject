#include "PixelExtractorFilter.hpp"
#include "Slice.hpp"

PixelExtractorFilter::PixelExtractorFilter()
{
	cachePath = Settings::PIXEL_EXTRACTOR_CACHE;
}

void PixelExtractorFilter::execute(const std::vector<std::filesystem::path>& paths, workspace& wspace)
{
	for (size_t i = 0; i < wspace.size(); ++i)
		submit(
			[&wspace, i, &paths]() { 
				Slice s{ paths.at(i) };
				wspace[i] = std::make_unique<types>(std::move(s)); 
			}
		);
	waitForFinish();
}