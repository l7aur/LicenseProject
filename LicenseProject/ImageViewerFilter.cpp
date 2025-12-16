#include "ImageViewerFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Filter.hpp"

#include <memory>

void ImageViewerFilter::loadCache()
{
}

void ImageViewerFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> ImageViewerFilter::process(const input_type* input) noexcept(false)
{
	return std::unique_ptr<DataInternalRepresentation>();
}
