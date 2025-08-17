#include "PixelExtractor.hpp"
#include "Slice.hpp"

PixelExtractor::PixelExtractor()
{
	workingDirectory = "./checkpoint/pixel_extractor/";
}

void PixelExtractor::execute(const std::vector<std::filesystem::path>& paths, workspace& wspace)
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