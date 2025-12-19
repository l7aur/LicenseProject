#include "ExecutionPipeline.hpp"
#include "PathToSliceConverterFilter.hpp"
#include "CannyEdgeDetectorFilter.hpp"
#include "ImageToPointSetConverterFilter.hpp"
#include "GlobalExceptionHandler.hpp"
#include "PointSetToMeshConverterFilter.hpp"
#include "MeshSerializerOBJFilter.hpp"
#include "ImageViewerFilter.hpp"
#include "MorphologicalFilter.hpp"
#include "Settings.hpp"
#include "SliceToImageConverterFilter.hpp"
#include "Workspace.hpp"

#include <memory>
#include "PointSetViewerFilter.hpp"

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
		pipeline.addFilter(std::make_unique<ImageViewerFilter>(
			Settings::IMAGE_VIEWER_CACHE));
		pipeline.addFilter(std::make_unique<ImageToPointSetConverterFilter>(
			Settings::IMAGE_TO_POINT_SET_CONVERTER_THRESHOLD_MIN,
			Settings::IMAGE_TO_POINT_SET_CONVERTER_THRESHOLD_MAX,
			Settings::IMAGE_TO_POINT_SET_CONVERTER_CACHE));
		pipeline.addFilter(std::make_unique<PointSetViewerFilter>(
			PointSetViewerFilter::Type::_3D,
			Settings::POINT_SET_VIEWER_CACHE));
		pipeline.addFilter(std::make_unique<PointSetToMeshConverterFilter>(
			Settings::POINT_SET_TO_MESH_CONVERTER_CACHE));
		pipeline.addFilter(std::make_unique<MeshSerializerOBJFilter>(
			Settings::MESH_SERIALIZER_CACHE));

		pipeline.execute(workspace);
	}
	catch (...) {
		GlobalExceptionHandler::handle();
	}
	return 0;
}

// TODO: nothing will work if the study is not in canonical coordinates