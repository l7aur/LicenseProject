#pragma once

#include "IFilter.hpp"
#include "Slice.hpp"
#include "Path.hpp"
#include "DataInternalRepresentation.hpp"

#include <filesystem>
#include <memory>

/**
 * .
 */
class PixelExtractorFilter : public IFilter<Path, Slice>
{
public:
	/**
	 * .
	 * 
	 * \param _cachePath
	 */
	PixelExtractorFilter(const std::filesystem::path& _cachePath) { cachePath = _cachePath; }

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
	std::unique_ptr<DataInternalRepresentation> process(const Path* input) noexcept(false) override;
};

