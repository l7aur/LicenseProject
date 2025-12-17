#pragma once

#include <string_view>
#include <opencv2/imgproc.hpp>

namespace Settings {
	// Pipeline
	constexpr bool USE_CACHING{ false };
	constexpr std::string_view EXECUTION_PIPELINE_SERIES_PATH{ "../dicom_data/test/" };
	//constexpr std::string_view EXECUTION_PIPELINE_SERIES_PATH{ "../dicom_data/CT2/" };

	// PixelExtractorFilter
	constexpr std::string_view PIXEL_EXTRACTOR_CACHE{ "./cache/pixel_extractor_filter/" };

	// CannyEdgeDetectorFilter
	constexpr int CANNY_MINIMUM_INTENSITY{ 0 };
	constexpr int CANNY_MAXIMUM_INTENSITY{ 10 };
	constexpr int CANNY_APERTURE_SIZE{ 3 };
	constexpr bool CANNY_ACCURATE_GRADIENT{ false };
	constexpr std::string_view CANNY_CACHE{ "./cache/canny_edge_detector_filter/" };


	// PointExtractorFilter
	constexpr std::string_view POINT_EXTRACTOR_CACHE{ "./cache/point_extractor_filter/" };

	// MeshCreatorFilter
	constexpr std::string_view MESH_CREATOR_CACHE{ "./cache/mesh_creator_filter/" };

	// MeshSerializerFilter
	constexpr std::string_view MESH_SERIALIZER_CACHE{ "./cache/mesh_serializer_filter/" };

	// ImageViewerFilter
	constexpr std::string_view IMAGE_VIEWER_CACHE{ "./cache/image_viewer_filter/" };

	// OpeningFilter
	constexpr unsigned int STRUCTURING_ELEMENT_WIDTH_OPENING{ 1 };
	constexpr unsigned int STRUCTURING_ELEMENT_HEIGHT_OPENING{ 1 };
	constexpr cv::MorphShapes STRUCTURING_ELEMENT_SHAPE_OPENING{ cv::MorphShapes::MORPH_CROSS };
	constexpr std::string_view OPENING_CACHE{ "./cache/opening_filter/" };

	// SliceToImageConverterFilter
	constexpr std::string_view SLICE_TO_IMAGE_CONVERTER_CACHE{ "./cache/slice_to_image_cnverter/" };
}