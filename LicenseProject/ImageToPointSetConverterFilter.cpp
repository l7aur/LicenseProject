#include "ImageToPointSetConverterFilter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Filter.hpp"
#include "Pixel.hpp"
#include "Point2.hpp"

#include <memory>
#include <utility>
#include <filesystem>

ImageToPointSetConverterFilter::ImageToPointSetConverterFilter(
    const Pixel& thresholdMin_,
    const Pixel& thresholdMax_,
    const std::filesystem::path& cachePath_)
    : Filter{ cachePath_ },
    thresholdMax{ thresholdMax_ },
    thresholdMin{ thresholdMin_ }
{
}

void ImageToPointSetConverterFilter::loadCache()
{
}

void ImageToPointSetConverterFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> ImageToPointSetConverterFilter::process(ImageToPointSetConverterFilter::input_type* input) noexcept(false)
{
    auto out = std::make_unique<output_type>(input->getTLHC(), input->getPixelSpacing());
    for (int i = 0; i < input->getHeight(); i++)
        for (int j = 0; j < input->getWidth(); j++)
            if (thresholdMin <= input->at(i, j) && input->at(i, j) <= thresholdMax)
                out->insert(Point2{ static_cast<double>(j), static_cast<double>(i) });

    return std::move(out);
}