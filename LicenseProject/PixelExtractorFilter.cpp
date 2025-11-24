#include "PixelExtractorFilter.hpp"

void PixelExtractorFilter::loadCache()
{
}

void PixelExtractorFilter::cache()
{
}

//void PixelExtractorFilter::execute(const std::vector<std::filesystem::path>& paths, std::vector<Workspace>& wspaces)
//{
//	try {
//		for (size_t i = 0; i < wspaces.size(); ++i)
//			submit(
//				[wspace = &wspaces, i, &paths]() {
//					Slice s{ paths.at(i) };
//					wspace = static_cast<Workspace>(std::move(s));
//				}
//			);
//	}
//	catch (...) {
//		GlobalExceptionHandler::handle();
//	}
//}