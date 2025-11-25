#pragma once

#include "IFilter.hpp"
#include "Slice.hpp"
#include "Image.hpp"
#include "DataInternalRepresentation.hpp"

#include <filesystem>
#include <memory>

/**
 * .
 */
class CannyEdgeDetectorFilter : public IFilter<Slice, Image>
{
public:
	/**
	 * .
	 * 
	 * \param _minIntensity
	 * \param _maxIntensity
	 * \param _apertureSize
	 * \param _accurateGrad
	 * \param _cachePath
	 */
	CannyEdgeDetectorFilter(
		const int _minIntensity,
		const int _maxIntensity,
		const int _apertureSize,
		const bool _accurateGrad,
		const std::filesystem::path& _cachePath
	);

	/**
	 * .
	 * 
	 */
	~CannyEdgeDetectorFilter() = default;

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

	std::unique_ptr<DataInternalRepresentation> process(const Slice* input) noexcept(false) override;

private:
	/**
	 * .
	 */
	const int minimumIntensity;

	/**
	 * .
	 */
	const int maximumIntensity;

	/**
	 * .
	 */
	const int apertureSize;

	/**
	 * .
	 */
	const bool useMoreAccurateGradient;
};

