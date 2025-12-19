#include "MeshSerializerOBJFilter.hpp"
#include "Filter.hpp"
#include "DataInternalRepresentation.hpp"

#include <memory>

void MeshSerializerOBJFilter::loadCache()
{
}

void MeshSerializerOBJFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> MeshSerializerOBJFilter::process(input_type* input) noexcept(false)
{
	return std::unique_ptr<DataInternalRepresentation>();
}
