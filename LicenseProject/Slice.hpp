#pragma once

#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmimgle/dcmimage.h>

#include <memory>
#include <string>
#include <cstdint>
#include <filesystem>

using pixel = uint16_t;

class Slice
{
public:
	Slice(const std::filesystem::path& p);
	~Slice() = default;

	[[nodiscard]] const float getPixelSpacingX() const { return pixelSpacing.first; }
	[[nodiscard]] const float getPixelSpacingY() const { return pixelSpacing.second; }
	[[nodiscard]] const pixel* const getPixels() const { return pixels.get(); }
	[[nodiscard]] const unsigned long getWidth() const { return width; }
	[[nodiscard]] const unsigned long getHeight() const { return height; }
	void setPixels(std::unique_ptr<pixel[]> newPxd) { pixels = std::move(newPxd); }
	
private:
	std::filesystem::path file{ "" };
	std::pair<float, float> pixelSpacing{ 0.0f, 0.0f };
	std::unique_ptr<pixel[]> pixels;
	unsigned long width{ 0 }, height{ 0 };
};

