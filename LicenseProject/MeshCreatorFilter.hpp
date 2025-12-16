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
class MeshCreatorFilter : public Filter<PointSet, Mesh> 
{
public:
	/**
	 * .
	 * 
	 * \param _cachePath
	 */
	MeshCreatorFilter(const std::filesystem::path& _cachePath) : Filter{ _cachePath } {}
	
	/**
	 * .
	 * 
	 */
	~MeshCreatorFilter() = default;

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
	std::unique_ptr<DataInternalRepresentation> process(const input_type* input) noexcept(false) override;
};
