#pragma once

#include "Filter.hpp"
#include "Mesh.hpp"
#include "DataInternalRepresentation.hpp"

#include <filesystem>
#include <memory>

/**
 * .
 */
class MeshSerializerFilter : public Filter<Mesh, Mesh> 
{
public:
	/**
	 * .
	 * 
	 * \param _cachePath
	 */
	MeshSerializerFilter(const std::filesystem::path& _cachePath) : Filter{ _cachePath } {}

	/**
	 * .
	 * 
	 */
	~MeshSerializerFilter() = default;

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
