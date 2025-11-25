#include "CannyEdgeDetectorFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "IFilter.hpp"

#include <filesystem>
#include <memory>

CannyEdgeDetectorFilter::CannyEdgeDetectorFilter(
    const int _minIntensity, const int _maxIntensity,
    const int _apertureSize, const bool _accurateGrad,
    const std::filesystem::path& _cachePath)
    : IFilter{ _cachePath },
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
    return std::unique_ptr<DataInternalRepresentation>();
}

//void CannyEdgeDetectorFilter::execute(const std::vector<std::filesystem::path>& paths, std::vector<Workspace>& wspaces)
//{
//    try {
//        for (size_t i = 0; i < wspaces.size(); ++i)
//            submit([this, &wspaces, i]
//                {
//                    Slice& s = std::get<Slice>(*wspaces.at(i));
//                    cv::Mat m{
//                        static_cast<int>(s.getHeight()),
//                        static_cast<int>(s.getWidth()),
//                        CV_8UC1,
//                        std::for_each(s.getPixels()->begin(), s.getPixels()->end(), [](const Pixel& p) { return p.getValue(); })
//                    };
//                    cv::Mat output{};
//                    cv::Canny(m, output, minimumIntensity, maximumIntensity, apertureSize, useMoreAccurateGradient);
//                    size_t bufferSize = (size_t)output.rows * (size_t)output.cols * output.elemSize();
//                    std::unique_ptr<std::vector<Pixel>> buffer = std::make_unique<std::vector<Pixel>>(bufferSize);
//                    std::memcpy(buffer.get(), output.data, bufferSize);
//                    s.setPixels(std::move(buffer));
//                });
//    } 
//    catch (...) {
//        GlobalExceptionHandler::handle();
//    }
//}