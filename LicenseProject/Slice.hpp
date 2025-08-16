#pragma once

#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmimgle/dcmimage.h>

#include <memory>
#include <string>
#include <cstdint>
#include <filesystem>

class Slice
{
public:
	Slice(const std::filesystem::path& p);
	~Slice() = default;

	[[nodiscard]] const float getPixelSpacingX() const { return pixelSpacing.first; }
	[[nodiscard]] const float getPixelSpacingY() const { return pixelSpacing.second; }
	[[nodiscard]] const int16_t* getPixels() const { return (int16_t*)img->getOutputData(2 * 8); }
	[[nodiscard]] const unsigned long getWidth() const { return img->getWidth(); }
	[[nodiscard]] const unsigned long getHeight() const { return img->getHeight(); }
	
private:
	std::filesystem::path file{ "" };
	std::pair<float, float> pixelSpacing{ 0.0f, 0.0f };
	std::unique_ptr<DicomImage> img;
};

