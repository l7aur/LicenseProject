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
	PointExtractorFilter(const std::filesystem::path& _cachePath) : IFilter{ _cachePath } {}
	
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
	std::unique_ptr<DataInternalRepresentation> process(const input_type* input)  noexcept(false) override;
};

