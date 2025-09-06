#include "Slice.hpp"
#include "PointSet.hpp"
#include "PointExtractorFilter.hpp"

PointExtractorFilter::PointExtractorFilter(const std::string_view& cachePath_)
{
	cachePath = cachePath_;
}

void PointExtractorFilter::execute(const std::vector<std::filesystem::path>& paths, std::vector<workspace>& wspaces)
{
	for (size_t i = 0; i < wspaces.size(); ++i)
		submit([&wspaces, i]
			{
				const Slice& s = std::get<Slice>(*wspaces[i]);
				const unsigned int width = s.getWidth();
				const unsigned int height = s.getHeight();
				PointSet ps{s.getUID(), s.getTLHC(), s.getPixelSpacingX(), s.getPixelSpacingY() };
				for (unsigned int y = 0; y < height; y++)
					for (unsigned int x = 0; x < width; x++)
						if (s.getPixels()[y * width + x] == pixel_max)
							ps.add({ x, y });
				wspaces[i] = std::make_unique<types>(std::move(ps));
			});
}
