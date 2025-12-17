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
class PixelExtractorFilter : public Filter<Path, Slice>
{
public:
	/**
	 * .
	 * 
	 * \param _cachePath
	 */
	PixelExtractorFilter(const std::filesystem::path& _cachePath) : Filter{ _cachePath } {}

	/**
	 * .
	 * 
	 */
	~PixelExtractorFilter() = default;

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

