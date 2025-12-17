#include "ExecutionPipeline.hpp"
#include "PathToSliceConverterFilter.hpp"
#include "CannyEdgeDetectorFilter.hpp"
#include "ImageToPointSetConverterFilter.hpp"
#include "GlobalExceptionHandler.hpp"
#include "PointSetToMeshConverterFilter.hpp"
#include "MeshSerializerFilter.hpp"
#include "ImageViewerFilter.hpp"
#include "MorphologicalFilter.hpp"
#include "Settings.hpp"
#include "SliceToImageConverterFilter.hpp"
#include "Workspace.hpp"

#include <memory>

int main() 
{
	Workspace workspace{ "../dicom_data/test/" };
	
	ExecutionPipeline pipeline{};

	try {
		pipeline.addFilter(std::make_unique<PathToSliceConverterFilter>(
			Settings::PATH_TO_SLICE_CONVERTER_CACHE));
		pipeline.addFilter(std::make_unique<SliceToImageConverterFilter>(
			Settings::SLICE_TO_IMAGE_CONVERTER_CACHE));
		pipeline.addFilter(std::make_unique<CannyEdgeDetectorFilter>(
			Settings::CANNY_MINIMUM_INTENSITY,
			Settings::CANNY_MAXIMUM_INTENSITY,
			Settings::CANNY_APERTURE_SIZE,
			Settings::CANNY_ACCURATE_GRADIENT,
			Settings::CANNY_CACHE));
		pipeline.addFilter(std::make_unique<MorphologicalFilter>(
			Settings::STRUCTURING_ELEMENT_WIDTH,
			Settings::STRUCTURING_ELEMENT_HEIGHT,
			Settings::STRUCTURING_ELEMENT_SHAPE,
			cv::MorphTypes::MORPH_OPEN,
			Settings::OPENING_CACHE));
		pipeline.addFilter(std::make_unique<ImageViewerFilter>(
			Settings::IMAGE_VIEWER_CACHE));
		//pipeline.addFilter(std::make_unique<ImageToPointSetConverterFilter>(
			//Settings::IMAGE_TO_POINT_SET_CONVERTER_CACHE));
		//pipeline.addFilter(std::make_unique<PointSetToMeshConverterFilter>(
			//Settings::MESH_CREATOR_CACHE));
		//pipeline.addFilter(std::make_unique<MeshSerializerFilter>(
			//Settings::MESH_SERIALIZER_CACHE));

		pipeline.execute(workspace);
	}
	catch (...) {
		GlobalExceptionHandler::handle();
	}
	return 0;
}