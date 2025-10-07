#include "../Core/ExecutionPipeline.hpp"
#include "../Filters/PixelExtractor/PixelExtractorFilter.hpp"
#include "../Filters/CannyEdge/CannyEdgeFilter.hpp"
#include "../Filterrs/PointExtractor/PointExtractor.hpp"
#include "../Misc/Settings.hpp"

int main() {

	// Create execution pipeline
	ExecutionPipeline pipeline{ Settings::EXECUTION_PIPELINE_SERIES_PATH };

	// Add filters
	pipeline.addFilter(std::make_unique<PixelExtractorFilter>(Settings::PIXEL_EXTRACTOR_CACHE));
	pipeline.addFilter(std::make_unique<CannyEdgeDetectorFilter>(
		Settings::CANNY_MINIMUM_INTENSITY,
		Settings::CANNY_MAXIMUM_INTENSITY,
		Settings::CANNY_APERTURE_SIZE,
		Settings::CANNY_ACCURATE_GRADIENT,
		Settings::CANNY_CACHE
	));
	pipeline.addFilter(std::make_unique<PointExtractorFilter>(Settings::POINT_EXTRACTOR_CACHE));

	// Execute pipeline
	Settings::USE_CACHING
		? pipeline.executeWithCaching()
		: pipeline.execute();

	// Display resulted images if workspace contains images
	pipeline.display();

	return 0;
}