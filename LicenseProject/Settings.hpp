#pragma once

#include <string_view>
#include <opencv2/imgproc.hpp>
#include "Pixel.hpp"

namespace Settings {
	// Pipeline
	constexpr bool USE_CACHING{ false };
	constexpr std::string_view EXECUTION_PIPELINE_SERIES_PATH{ "../dicom_data/test/" };
	//constexpr std::string_view EXECUTION_PIPELINE_SERIES_PATH{ "../dicom_data/CT2/" };

	// PathToSliceConverterFilter
	constexpr std::string_view PATH_TO_SLICE_CONVERTER_CACHE{ "./cache/pixel_extractor_filter/" };

	// CannyEdgeDetectorFilter
	constexpr int CANNY_MINIMUM_INTENSITY{ 0 };
	constexpr int CANNY_MAXIMUM_INTENSITY{ 10 };
	constexpr int CANNY_APERTURE_SIZE{ 3 };
	constexpr bool CANNY_ACCURATE_GRADIENT{ false };
	constexpr std::string_view CANNY_CACHE{ "./cache/canny_edge_detector_filter/" };

	// ImageToPointSetFilter
	constexpr std::string_view IMAGE_TO_POINT_SET_CONVERTER_CACHE{ "./cache/image_to_pointset_converter_filter/" };

	// PointSetToMeshConverterFilter
	constexpr std::string_view POINT_SET_TO_MESH_CONVERTER_CACHE{ "./cache/mesh_creator_filter/" };

	// MeshSerializerOBJFilter
	constexpr std::string_view MESH_SERIALIZER_CACHE{ "./cache/mesh_serializer_filter/" };

	// ImageViewerFilter
	constexpr std::string_view IMAGE_VIEWER_CACHE{ "./cache/image_viewer_filter/" };

	// MorphologicalFilter
	constexpr unsigned int STRUCTURING_ELEMENT_WIDTH{ 1 };
	constexpr unsigned int STRUCTURING_ELEMENT_HEIGHT{ 1 };
	constexpr cv::MorphShapes STRUCTURING_ELEMENT_SHAPE{ cv::MorphShapes::MORPH_CROSS };
	constexpr std::string_view OPENING_CACHE{ "./cache/opening_filter/" };

	// SliceToImageConverterFilter
	constexpr std::string_view SLICE_TO_IMAGE_CONVERTER_CACHE{ "./cache/slice_to_image_converter_filter/" };

	// PointSetViewerFilter
	constexpr std::string_view POINT_SET_VIEWER_CACHE{ "./cache/pointset_viewer_filter/" };
	constexpr Pixel IMAGE_TO_POINT_SET_CONVERTER_THRESHOLD_MIN{ (PixelMin() + PixelMax()) / 2 };
	constexpr Pixel IMAGE_TO_POINT_SET_CONVERTER_THRESHOLD_MAX{ PixelMax() };
}