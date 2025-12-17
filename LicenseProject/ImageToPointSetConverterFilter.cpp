#include "ImageToPointSetConverterFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Filter.hpp"

#include <memory>

void ImageToPointSetConverterFilter::loadCache()
{
}

void ImageToPointSetConverterFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> ImageToPointSetConverterFilter::process(ImageToPointSetConverterFilter::input_type* input) noexcept(false)
{
    return std::unique_ptr<DataInternalRepresentation>();
}

//void ImageToPointSetConverterFilter::execute(const std::vector<std::filesystem::path>& paths, std::vector<Workspace>& wspaces)
//{
//	try {
//		for (size_t i = 0; i < wspaces.size(); ++i)
//			submit([&wspaces, i]
//				{
//					const Slice& s = std::get<Slice>(*wspaces[i]);
//					const unsigned int width = s.getWidth();
//					const unsigned int height = s.getHeight();
//					PointSet ps{ s.getUID(), s.getTLHC(), s.getPixelSpacingX(), s.getPixelSpacingY() };
//					for (unsigned int y = 0; y < height; y++)
//						for (unsigned int x = 0; x < width; x++)
//							if (s.getPixels()[y * width + x] == PIXEL_MAX)
//								ps.inserty({ x, y });
//					wspaces[i] = std::make_unique<types>(std::move(ps));
//				});
//	}
//	catch (...) {
//		GlobalExceptionHandler::handle();
//	}
//}