#include "MeshCreatorFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Filter.hpp"

#include <memory>

void MeshCreatorFilter::loadCache()
{
}

void MeshCreatorFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> MeshCreatorFilter::process(const input_type* input) noexcept(false)
{
	return std::unique_ptr<DataInternalRepresentation>();
}
