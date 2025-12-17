#include "ImageViewerFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Filter.hpp"

#include <memory>
#include <opencv2/highgui.hpp>
#include <sstream>
#include <thread>

void ImageViewerFilter::loadCache()
{
}

void ImageViewerFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> ImageViewerFilter::process(input_type* input) noexcept(false)
{
	std::stringstream ss;
	ss << std::this_thread::get_id();

	mtx.lock();
	cv::imshow("Thread id:" + ss.str(), input->getImage());
	cv::waitKey(0);
	mtx.unlock();

	return std::make_unique<output_type>(*input);
}
