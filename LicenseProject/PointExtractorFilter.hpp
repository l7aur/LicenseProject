#pragma once

#include "IFilter.hpp"
#include "Slice.hpp"
#include "PointSet.hpp"
#include "DataInternalRepresentation.hpp"

#include <filesystem>
#include <memory>

/**
 * .
 */
class PointExtractorFilter : public IFilter<Slice, PointSet>
{
public:
	/**
	 * .
	 * 
	 * \param _cachePath
	 */
	PointExtractorFilter(const std::filesystem::path& _cachePath) { cachePath = _cachePath; }
	
	/**
	 * .
	 * 
	 */
	~PointExtractorFilter() = default;

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
	std::unique_ptr<DataInternalRepresentation> process(const Slice* input)  noexcept(false) override;
};

