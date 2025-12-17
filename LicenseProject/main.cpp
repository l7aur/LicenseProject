#include "ExecutionPipeline.hpp"
#include "PixelExtractorFilter.hpp"
#include "CannyEdgeDetectorFilter.hpp"
#include "PointExtractorFilter.hpp"
#include "GlobalExceptionHandler.hpp"
#include "MeshCreatorFilter.hpp"
#include "MeshSerializerFilter.hpp"
#include "ImageViewerFilter.hpp"
#include "OpeningFilter.hpp"
#include "Settings.hpp"
#include "SliceToImageConverterFilter.hpp"
#include "Workspace.hpp"

#include <memory>

int main() 
{
	Workspace workspace{ "../dicom_data/test/" };
	
	ExecutionPipeline pipeline{};

	try {
		pipeline.addFilter(std::make_unique<PixelExtractorFilter>(
			Settings::PIXEL_EXTRACTOR_CACHE));
		pipeline.addFilter(std::make_unique<SliceToImageConverterFilter>(
			Settings::SLICE_TO_IMAGE_CONVERTER_CACHE));
		pipeline.addFilter(std::make_unique<CannyEdgeDetectorFilter>(
			Settings::CANNY_MINIMUM_INTENSITY,
			Settings::CANNY_MAXIMUM_INTENSITY,
			Settings::CANNY_APERTURE_SIZE,
			Settings::CANNY_ACCURATE_GRADIENT,
			Settings::CANNY_CACHE));
		pipeline.addFilter(std::make_unique<OpeningFilter>(
			Settings::STRUCTURING_ELEMENT_WIDTH_OPENING,
			Settings::STRUCTURING_ELEMENT_HEIGHT_OPENING,
			Settings::STRUCTURING_ELEMENT_SHAPE_OPENING,
			Settings::OPENING_CACHE));
		pipeline.addFilter(std::make_unique<ImageViewerFilter>(
			Settings::IMAGE_VIEWER_CACHE));
		//pipeline.addFilter(std::make_unique<PointExtractorFilter>(
			//Settings::POINT_EXTRACTOR_CACHE));
		//pipeline.addFilter(std::make_unique<MeshCreatorFilter>(
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