#include "CannyEdgeDetectorFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Filter.hpp"

#include <filesystem>
#include <memory>

#include <utility>
#include <opencv2/imgproc.hpp>

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
    static_assert(sizeof(Pixel) == 1, "cv::Canny does not support pixel values larger than 255!");
    static_assert(PixelCVImageTypeMacro == CV_8UC1, "cv::Canny does not support pixel values larger than 255!");

    auto temp = output_type(input->getWidth(), input->getHeight(), input->getPixels()->data());
    auto out = std::make_unique<output_type>();
    cv::Canny(temp.getImage(), out->imageHandle(), minimumIntensity, maximumIntensity, apertureSize, useMoreAccurateGradient);
    return std::move(out);
}