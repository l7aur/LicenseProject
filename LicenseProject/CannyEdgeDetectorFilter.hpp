#pragma once

#include "IFilter.hpp"
#include "Slice.hpp"
#include "Image.hpp"

#include <filesystem>

class CannyEdgeDetectorFilter : public IFilter<Slice, Image>
{
public:
	CannyEdgeDetectorFilter(
		const int _minIntensity,
		const int _maxIntensity,
		const int _apertureSize,
		const bool _accurateGrad,
		const std::filesystem::path& _cachePath
	);
	~CannyEdgeDetectorFilter() = default;

	void loadCache() override;
	void cache() override;

private:
	const int minimumIntensity, maximumIntensity;
	const int apertureSize;
	const bool useMoreAccurateGradient;
};

