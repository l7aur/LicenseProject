#include "ExecutionPipeline.hpp"
#include "PixelExtractor.hpp"
#include "ContourExtractor.hpp"
#include "Settings.hpp"

int main() {
	ExecutionPipeline pipeline{"../dicom_data/test/"};

	pipeline.addFilter(std::make_unique<PixelExtractor>());
	pipeline.addFilter(std::make_unique<ContourExtractor>());

	Settings::withCheckpoints
		? pipeline.executeWithCheckpoints()
		: pipeline.executeWithoutCheckpoints();

	return 0;
}