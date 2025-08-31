#include "CannyEdgeDetectorFilter.hpp"
#include "Slice.hpp"

#include <windows.h>
#include <algorithm>
#include <variant>

#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>


CannyEdgeDetectorFilter::CannyEdgeDetectorFilter(
    const int minIntensity,
    const int maxIntensity,
    const int apertureSize_,
    const bool accurateGrad,
    const std::string_view& cachePath_
)
    :
    minimumIntensity{ minIntensity }, maximumIntensity{ maxIntensity },
    apertureSize{ apertureSize_ }, useMoreAccurateGradient{ accurateGrad }
{
    cachePath = cachePath_;
}

void CannyEdgeDetectorFilter::execute(const std::vector<std::filesystem::path>& paths, workspace& wspace)
{
    for (size_t i = 0; i < wspace.size(); ++i)
        submit([this, &wspace, i]
            {
                Slice& s = std::get<Slice>(*wspace.at(i));
                cv::Mat m{
                    static_cast<int>(s.getHeight()),
                    static_cast<int>(s.getWidth()),
                    CV_8UC1,
                    s.getPixels()
                };
                cv::Mat output{};
                cv::Canny(m, output, minimumIntensity, maximumIntensity, apertureSize, useMoreAccurateGradient);
                size_t bufferSize = (size_t)output.rows * (size_t)output.cols * output.elemSize();
                std::unique_ptr<pixel[]> buffer = std::make_unique<pixel[]>(bufferSize);
                std::memcpy(buffer.get(), output.data, bufferSize);
                s.setPixels(std::move(buffer));
            });
    waitForFinish();
}
