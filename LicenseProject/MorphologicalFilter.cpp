#include "MorphologicalFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Filter.hpp"

#include <opencv2/imgproc.hpp>
#include <opencv2/core/types.hpp>
#include <memory>
#include <filesystem>

MorphologicalFilter::MorphologicalFilter(
	const unsigned int _structuringElementWidth,
	const unsigned int _structuringElementHeight,
	cv::MorphShapes _structuringElementShape,
	cv::MorphTypes _morphologicalType,
	const std::filesystem::path& _cachePath)
	: Filter{ _cachePath },
	structuringElementShape{ _structuringElementShape },
	structuringElementHeight{ _structuringElementHeight },
	structuringElementWidth{ _structuringElementWidth },
	morphologicalType{ _morphologicalType }
{
}

void MorphologicalFilter::loadCache()
{
}

void MorphologicalFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> MorphologicalFilter::process(input_type* input) noexcept(false)
{
	cv::morphologyEx(
		input->imageHandle(),
		input->imageHandle(),
		morphologicalType,
		cv::getStructuringElement(
			structuringElementShape, 
			cv::Size(
				structuringElementWidth, 
				structuringElementHeight
	)));
	return std::make_unique<output_type>(*input);
}
