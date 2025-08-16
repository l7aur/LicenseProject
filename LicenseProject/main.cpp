#include "ExecutionPipeline.hpp"
#include "PixelExtractor.hpp"
#include "ContourExtractor.hpp"
#include "Settings.hpp"

int main() {
	ExecutionPipeline pipeline{"../dicom_data/Series 201 [CT - CRANE SANS]/"};

	pipeline.addFilter(std::make_unique<PixelExtractor>());
	pipeline.addFilter(std::make_unique<ContourExtractor>());

	pipeline.setup();

	Settings::withCheckpoints
		? pipeline.executeWithCheckpoints()
		: pipeline.executeWithoutCheckpoints();

	return 0;
}