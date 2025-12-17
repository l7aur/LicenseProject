#pragma once

#include "Filter.hpp"
#include "Slice.hpp"
#include "Path.hpp"
#include "DataInternalRepresentation.hpp"

#include <filesystem>
#include <memory>

/**
 * .
 */
class PathToSliceConverterFilter : public Filter<Path, Slice>
{
public:
	/**
	 * .
	 * 
	 * \param _cachePath
	 */
	PathToSliceConverterFilter(const std::filesystem::path& _cachePath) : Filter{ _cachePath } {}

	/**
	 * .
	 * 
	 */
	~PathToSliceConverterFilter() = default;

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

