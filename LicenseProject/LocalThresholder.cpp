#include "LocalThresholder.hpp"
#include "Slice.hpp"

#include <algorithm>

#include <opencv2/opencv.hpp>

std::function<void()> LocalThresholder::execute(workspace& wspace, size_t index)
{
    return [&wspace, index]() {
        constexpr int KERNEL_SIZE = 5;
        constexpr int K_HALF = KERNEL_SIZE / 2;

        Slice& s = std::get<Slice>(*wspace[index]);
        const int height = static_cast<int>(s.getHeight());
        const int width = static_cast<int>(s.getWidth());
        pixel* const pxd = s.getPixels();

        std::unique_ptr<pixel[]> newPxd = std::make_unique<pixel[]>(static_cast<size_t>(height * width));
        if (newPxd == nullptr)
            std::exit(-999);

        // de gandit puternic pt contour extraction
        for (int y = K_HALF; y < height - K_HALF; y += KERNEL_SIZE)
            for (int x = K_HALF; x < width - K_HALF; x += KERNEL_SIZE) {
                std::array<pixel, static_cast<size_t>(KERNEL_SIZE* KERNEL_SIZE)> kernel{};

                for (int q = -K_HALF; q <= K_HALF; ++q)
                    for (int p = -K_HALF; p <= K_HALF; ++p)
                        kernel.at(static_cast<size_t>((K_HALF + q) * KERNEL_SIZE + K_HALF + p)) = pxd[(y + q) * width + x + p];

                std::sort(kernel.begin(), kernel.end());
                const pixel threshold = kernel.at(kernel.size() / 2);

                for (int q = -K_HALF; q <= K_HALF; ++q)
                    for (int p = -K_HALF; p <= K_HALF; ++p)
                        newPxd.get()[(y + q) * width + x + p] = (pxd[(y + q) * width + x + p] < threshold)
                            ? PIXEL_MIN
                            : PIXEL_MAX;
            }

        cv::Mat m{ (int)height, (int)width, CV_16UC1, newPxd.get() };
        cv::imshow("haha", m);
        cv::waitKey(0);

        s.setPixels(std::move(newPxd));
    };
}
