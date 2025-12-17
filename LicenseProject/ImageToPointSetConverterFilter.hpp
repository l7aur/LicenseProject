#pragma once

#include "Filter.hpp"
#include "Slice.hpp"
#include "PointSet.hpp"
#include "DataInternalRepresentation.hpp"

#include <filesystem>
#include <memory>

/**
 * .
 */
class ImageToPointSetConverterFilter : public Filter<Slice, PointSet>
{
public:
	/**
	 * .
	 * 
	 * \param _cachePath
	 */
	ImageToPointSetConverterFilter(const std::filesystem::path& _cachePath) : Filter{ _cachePath } {}
	
	/**
	 * .
	 * 
	 */
	~ImageToPointSetConverterFilter() = default;

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
	std::unique_ptr<DataInternalRepresentation> process(input_type* input)  noexcept(false) override;
};

