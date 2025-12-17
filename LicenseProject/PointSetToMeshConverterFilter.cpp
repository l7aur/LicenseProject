#include "PointSetToMeshConverterFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Filter.hpp"

#include <memory>

void PointSetToMeshConverterFilter::loadCache()
{
}

void PointSetToMeshConverterFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> PointSetToMeshConverterFilter::process(input_type* input) noexcept(false)
{
	return std::unique_ptr<DataInternalRepresentation>();
}
