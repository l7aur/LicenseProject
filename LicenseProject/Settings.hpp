#pragma once

#include <string_view>

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
}