#include "PathToSliceConverterFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Filter.hpp"

#include <memory>

void PathToSliceConverterFilter::loadCache()
{
}

void PathToSliceConverterFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> PathToSliceConverterFilter::process(PathToSliceConverterFilter::input_type* input) noexcept(false)
{
    return std::make_unique<output_type>(input->getPath());
}