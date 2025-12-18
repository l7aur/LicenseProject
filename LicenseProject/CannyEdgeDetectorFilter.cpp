#include "CannyEdgeDetectorFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Filter.hpp"
#include "Pixel.hpp"

#include <filesystem>
#include <memory>
#include <opencv2/imgproc.hpp>
#include <stdexcept>
#include <opencv2/core/hal/interface.h>

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

std::unique_ptr<DataInternalRepresentation> CannyEdgeDetectorFilter::process(CannyEdgeDetectorFilter::input_type* input) noexcept(false)
{
    // TODO: ideally this should happen at compile time iff the filter is used in the pipeline
    if (sizeof(Pixel) != 1)
        throw std::runtime_error("cv::Canny does not support pixel values larger than 255!");
    if (PixelCVImageTypeMacro != CV_8UC1)
        throw std::runtime_error("cv::Canny does not support pixel values larger than 255!");

    cv::Canny(input->imageHandle(), input->imageHandle(), minimumIntensity, maximumIntensity, apertureSize, useMoreAccurateGradient);
    return std::make_unique<output_type>(*input);
}