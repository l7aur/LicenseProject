#pragma once

#include <memory>
#include <string>
#include <filesystem>

#include "Warnings.hpp"
#include "Settings.hpp"
#include "matrix.hpp"

#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmimgle/dcmimage.h>

class DicomImage;

class Slice
{
public:
	Slice(const std::string& path) noexcept(false);
	~Slice() = default;
	static void process(const size_t i, const std::string path, std::vector<matrix<Settings::pixel>>& mat);
	void saveCheckpoint(const std::filesystem::path& folderPath);

	MUST_USE_VALUE_ATTR const std::string& getFileName() const { return fileName; }
	MUST_USE_VALUE_ATTR const size_t getNumberOfRows() const { return img->getHeight(); }
	MUST_USE_VALUE_ATTR const size_t getNumberOfColumns() const { return img->getWidth(); }
	MUST_USE_VALUE_ATTR const uint16_t* const getPixelData() const { return static_cast<const uint16_t*>(img->getOutputData(sizeof(uint16_t) * 8)); }
	MUST_USE_VALUE_ATTR const float getPixelSpacingX() const { return pixelSpacing.first; }
	MUST_USE_VALUE_ATTR const float getPixelSpacingY() const { return pixelSpacing.second; }
	MUST_USE_VALUE_ATTR matrix<Settings::pixel> convertToMatrix() const;

private:
	const std::string fileName{ "" };
	std::unique_ptr<DicomImage> img{ nullptr };
	const std::pair<float, float> pixelSpacing{ 0.0f, 0.0f };
};

