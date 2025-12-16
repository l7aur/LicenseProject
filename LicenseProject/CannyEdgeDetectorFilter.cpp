#include "CannyEdgeDetectorFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Filter.hpp"

#include <filesystem>
#include <memory>

CannyEdgeDetectorFilter::CannyEdgeDetectorFilter(
    const int _minIntensity, const int _maxIntensity,
    const int _apertureSize, const bool _accurateGrad,
    const std::filesystem::path& _cachePath)
    : Filter{ _cachePath },
    minimumIntensity{ _minIntensity }, maximumIntensity{ _maxIntensity },
    apertureSize{ _apertureSize }, useMoreAccurateGradient{ _accurateGrad }
{
}

void CannyEdgeDetectorFilter::loadCache()
{
}

void CannyEdgeDetectorFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> CannyEdgeDetectorFilter::process(const CannyEdgeDetectorFilter::input_type* input) noexcept(false)
{
    return std::make_unique<output_type>(input->getWidth(), input->getHeight(), input->getPixels()->data());
}