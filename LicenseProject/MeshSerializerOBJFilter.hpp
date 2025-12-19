#pragma once

#include "Filter.hpp"
#include "Mesh.hpp"
#include "DataInternalRepresentation.hpp"

#include <filesystem>
#include <memory>

/**
 * .
 */
class MeshSerializerOBJFilter : public Filter<Mesh, Mesh> 
{
public:
	/**
	 * .
	 * 
	 * \param _cachePath
	 */
	MeshSerializerOBJFilter(const std::filesystem::path& _cachePath) : Filter{ _cachePath } {}

	/**
	 * .
	 * 
	 */
	~MeshSerializerOBJFilter() = default;

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
