#include "ExecutionPipeline.hpp"
#include "PixelExtractor.hpp"
#include "ContourExtractor.hpp"

namespace Settings {
	const bool withCheckpoints{ false };
}

int main() {
	ExecutionPipeline pipeline{"../dicom_data/Series 201 [CT - CRANE SANS]/"};

	pipeline.addFilter(std::make_unique<PixelExtractor>());
	pipeline.addFilter(std::make_unique<ContourExtractor>());

	pipeline.execute(Settings::withCheckpoints);

	return 0;
}