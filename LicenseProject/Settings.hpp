#pragma once

#include <memory>
#include <vector>
#include <variant>
#include <string_view>
#include <cstdint>

class Slice;

using types = std::variant<Slice, int>;
using workspace = std::vector<std::unique_ptr<types>>;
using pixel = uint8_t;

#define PIXEL_MAX static_cast<pixel>(UINT16_MAX)
#define PIXEL_MIN static_cast<pixel>(0)

namespace Settings {
	// Pipeline
	const bool USE_CACHING{ false };

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