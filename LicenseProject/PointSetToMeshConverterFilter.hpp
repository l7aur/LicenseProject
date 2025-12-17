#pragma once

#include "Mesh.hpp"
#include "Filter.hpp"
#include "PointSet.hpp"
#include "DataInternalRepresentation.hpp"

#include <filesystem>
#include <memory>

/**
 * .
 */
class PointSetToMeshConverterFilter : public Filter<PointSet, Mesh> 
{
public:
	/**
	 * .
	 * 
	 * \param _cachePath
	 */
	PointSetToMeshConverterFilter(const std::filesystem::path& _cachePath) : Filter{ _cachePath } {}
	
	/**
	 * .
	 * 
	 */
	~PointSetToMeshConverterFilter() = default;

	/**
	 * .
	 * 
	 */
	void loadCache() override;

	/**
	 * .
	 * 
	 */
	void cache() override;

	/**
	 * .
	 * 
	 * \param input
	 * \return 
	 */
	std::unique_ptr<DataInternalRepresentation> process(input_type* input) noexcept(false) override;
};
