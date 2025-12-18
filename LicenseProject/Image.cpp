#include "Image.hpp"
#include "Pixel.hpp"
#include "Point3.hpp"

#include <utility>
#include <string.h>

Image::Image(
	const unsigned int width,
	const unsigned int height,
	const std::pair<float, float> _pixelSpacing,
	const Point3 _tlhc,
	const Pixel* pixels)
	: img(static_cast<int>(height), static_cast<int>(width), PixelCVImageTypeMacro),
	pixelSpacing{ _pixelSpacing },
	tlhc{ _tlhc }
{
	std::memcpy(img.data, pixels, static_cast<size_t>(width) * static_cast<size_t>(height) * sizeof(Pixel));
}
