#include "CannyEdgeDetectorFilter.hpp"
#include "Slice.hpp"

#include <windows.h>
#include <algorithm>
#include <variant>

#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>


CannyEdgeDetectorFilter::CannyEdgeDetectorFilter()
{
    cachePath = Settings::CANNY_CACHE;
}

void CannyEdgeDetectorFilter::execute(const std::vector<std::filesystem::path>& paths, workspace& wspace)
{
    for (size_t i = 0; i < wspace.size(); ++i)
        submit([i, &wspace]
            {
                Slice& s = std::get<Slice>(*wspace.at(i));
                cv::Mat m{
                    static_cast<int>(s.getHeight()),
                    static_cast<int>(s.getWidth()),
                    CV_8UC1,
                    s.getPixels()
                };
                cv::Mat output{};
                cv::Canny(m, output, Settings::CANNY_MINIMUM_INTENSITY, Settings::CANNY_MAXIMUM_INTENSITY, Settings::CANNY_APERTURE_SIZE, Settings::CANNY_ACCURATE_GRADIENT);
                size_t bufferSize = (size_t)output.rows * (size_t)output.cols * output.elemSize();
                std::unique_ptr<pixel[]> buffer = std::make_unique<pixel[]>(bufferSize);
                std::memcpy(buffer.get(), output.data, bufferSize);
                s.setPixels(std::move(buffer));
            });
    waitForFinish();
}
