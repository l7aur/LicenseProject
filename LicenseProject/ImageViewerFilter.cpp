#include "ImageViewerFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Filter.hpp"

#include <memory>
#include <opencv2/highgui.hpp>
#include <utility>

void ImageViewerFilter::loadCache()
{
}

void ImageViewerFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> ImageViewerFilter::process(const input_type* input) noexcept(false)
{
	cv::imshow("Image", input->getImage());
	cv::waitKey(0);
	return std::make_unique<output_type>(std::move(*input));
}
