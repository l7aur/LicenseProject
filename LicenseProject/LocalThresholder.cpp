#include "LocalThresholder.hpp"
#include "Slice.hpp"

#include <algorithm>

#include <opencv2/opencv.hpp>

std::function<void()> LocalThresholder::execute(std::vector<std::pair<std::filesystem::path, std::unique_ptr<Slice>>>& wspace, int index)
{
    return [&wspace, index]() {
        const int KERNEL_SIZE = 5;
        unsigned long height = wspace[index].second->getHeight();
        unsigned long width = wspace[index].second->getWidth();
        const uint16_t* pxd = wspace[index].second->getPixels();
        uint16_t* newPxd = new uint16_t[height * width];
        if (newPxd == nullptr)
            std::exit(-999);

        for (unsigned long y = KERNEL_SIZE / 2; y <= height - KERNEL_SIZE / 2; y += KERNEL_SIZE)
            for (unsigned long x = KERNEL_SIZE / 2; x <= width - KERNEL_SIZE / 2; x += KERNEL_SIZE) {
                std::vector<int16_t> kernel(KERNEL_SIZE * KERNEL_SIZE, 0);
                for (int q = -KERNEL_SIZE / 2; q <= KERNEL_SIZE / 2; ++q)
                    for (int p = -KERNEL_SIZE / 2; p <= KERNEL_SIZE / 2; ++p)
                        kernel[(size_t)((KERNEL_SIZE / 2 + q) * KERNEL_SIZE + KERNEL_SIZE / 2 + p)] = pxd[(y + q) * width + x + p];
                std::sort(kernel.begin(), kernel.end());
                const uint16_t threshold = kernel.at(kernel.size() / 2);

                for (int q = -KERNEL_SIZE / 2; q <= KERNEL_SIZE / 2; ++q)
                    for (int p = -KERNEL_SIZE / 2; p <= KERNEL_SIZE / 2; ++p)
                        newPxd[(y + q) * width + x + p] = static_cast<uint16_t>(pxd[(y + q) * width + x + p] < threshold ? UINT16_MAX : static_cast<uint16_t>(0));
            }
        cv::Mat m{ (int)height, (int)width, CV_16UC1, newPxd };
        cv::imshow("haha", m);
        cv::waitKey(0);
        delete[] newPxd;
    };
}
