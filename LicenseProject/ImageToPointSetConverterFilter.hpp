#pragma once

#include "Filter.hpp"
#include "Image.hpp"
#include "PointSet.hpp"
#include "DataInternalRepresentation.hpp"
#include "Pixel.hpp"

#include <filesystem>
#include <memory>

/**
 * .
 */
class ImageToPointSetConverterFilter : public Filter<Image, PointSet>
{
public:
	/**
	 * .
	 * 
	 * \param thresholdMin
	 * \param thresholdMax
	 * \param _cachePath
	 */
	ImageToPointSetConverterFilter(
		const Pixel& thresholdMin_,
		const Pixel& thresholdMax_,
		const std::filesystem::path& cachePath_);
	
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
	std::unique_ptr<DataInternalRepresentation> process(input_type* input) noexcept(false) override;

private:
	const Pixel thresholdMin;
	const Pixel thresholdMax;
};

