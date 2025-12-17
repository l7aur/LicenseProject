#include "PixelExtractorFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Filter.hpp"

#include <memory>

void PixelExtractorFilter::loadCache()
{
}

void PixelExtractorFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> PixelExtractorFilter::process(PixelExtractorFilter::input_type* input) noexcept(false)
{
    return std::make_unique<output_type>(input->getPath());
}