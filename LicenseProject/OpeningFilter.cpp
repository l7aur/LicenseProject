#include "OpeningFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Filter.hpp"

#include <opencv2/imgproc.hpp>
#include <opencv2/core/types.hpp>
#include <memory>
#include <filesystem>

OpeningFilter::OpeningFilter(
	const unsigned int _structuringElementWidth,
	const unsigned int _structuringElementHeight,
	cv::MorphShapes _structuringElementShape,
	const std::filesystem::path& _cachePath)
	: Filter{ _cachePath },
	structuringElementShape{ _structuringElementShape },
	structuringElementHeight{ _structuringElementHeight },
	structuringElementWidth{ _structuringElementWidth }
{
}

void OpeningFilter::loadCache()
{
}

void OpeningFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> OpeningFilter::process(input_type* input) noexcept(false)
{
	cv::morphologyEx(
		input->imageHandle(),
		input->imageHandle(),
		cv::MorphTypes::MORPH_ERODE,
		cv::getStructuringElement(
			structuringElementShape, 
			cv::Size(
				structuringElementWidth, 
				structuringElementHeight
	)));
	return std::make_unique<output_type>(*input);
}
