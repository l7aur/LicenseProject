#include "Image.hpp"
#include "Pixel.hpp"

#include <string.h>

Image::Image(const unsigned int width, const unsigned int height, const Pixel* pixels)
	: img(static_cast<int>(height), static_cast<int>(width), PixelCVImageTypeMacro)
{
	std::memcpy(img.data, pixels, static_cast<size_t>(width) * static_cast<size_t>(height) * sizeof(Pixel));
}
