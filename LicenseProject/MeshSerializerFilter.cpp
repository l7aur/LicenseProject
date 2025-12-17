#include "MeshSerializerFilter.hpp"
#include "Filter.hpp"
#include "DataInternalRepresentation.hpp"

#include <memory>

void MeshSerializerFilter::loadCache()
{
}

void MeshSerializerFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> MeshSerializerFilter::process(input_type* input) noexcept(false)
{
	return std::unique_ptr<DataInternalRepresentation>();
}
