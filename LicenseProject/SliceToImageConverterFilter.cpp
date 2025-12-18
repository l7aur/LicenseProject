#include "SliceToImageConverterFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Filter.hpp"

#include <memory>

void SliceToImageConverterFilter::loadCache()
{
}

void SliceToImageConverterFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> SliceToImageConverterFilter::process(input_type* input) noexcept(false)
{
	return std::make_unique<output_type>(
		input->getWidth(), 
		input->getHeight(),
		input->getPixelSpacing(),
		input->getTLHC(),
		input->getPixels()->data());
}
