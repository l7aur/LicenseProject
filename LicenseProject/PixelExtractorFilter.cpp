#include "PixelExtractorFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Path.hpp"

#include <memory>

void PixelExtractorFilter::loadCache()
{
}

void PixelExtractorFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> PixelExtractorFilter::process(const Path* input) noexcept(false)
{
    return std::unique_ptr<DataInternalRepresentation>();
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