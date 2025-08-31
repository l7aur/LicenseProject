#include "ExecutionPipeline.hpp"
#include "PixelExtractorFilter.hpp"
#include "CannyEdgeDetectorFilter.hpp"
#include "PointExtractorFilter.hpp"
#include "Settings.hpp"

int main() {

	// Create execution pipeline
	ExecutionPipeline pipeline{"../dicom_data/test/"};

	pipeline.addFilter(std::make_unique<PixelExtractorFilter>());
	pipeline.addFilter(std::make_unique<CannyEdgeDetectorFilter>());

	// Execute pipeline
	Settings::USE_CACHING
		? pipeline.executeWithCaching()
		: pipeline.execute();

	// Display resulted images
	pipeline.display();

	return 0;
}