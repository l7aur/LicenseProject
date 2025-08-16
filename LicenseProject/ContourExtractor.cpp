#include "ContourExtractor.hpp"
#include "Slice.hpp"

#include <array>

#include "opencv2/opencv.hpp"

ContourExtractor::ContourExtractor()
{
	workingDirectory = "./checkpoint/contour_extractor/";
}

void ContourExtractor::execute(std::vector<std::pair<std::filesystem::path, std::unique_ptr<Slice>>>& wspace)
{
	for (size_t i = 0; i < wspace.size(); ++i)
		submit([&wspace, i]() {
			//histogram
			//2 median thresholding

			unsigned long height = wspace[i].second->getHeight();
			unsigned long width = wspace[i].second->getWidth();
			const uint16_t* pxd = wspace[i].second->getPixels();
			for (unsigned long y = 0; y < height; ++y)
				for (unsigned long x = 0; x < width; ++x)
					;

			cv::Mat m{ (int)height, (int)width, CV_16UC1, const_cast<uint16_t*>(pxd) };
			cv::imshow("haha", m);
			cv::waitKey(0);
		});
	waitForFinish();
	std::cout << "done\n";
}
