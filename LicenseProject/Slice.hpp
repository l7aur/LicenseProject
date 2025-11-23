#pragma once

#include "Types.hpp"
#include "IWorkspace.hpp"

#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmimgle/dcmimage.h>

#include <memory>
#include <string>
#include <utility>
#include <filesystem>

class Slice : public IWorkspace
{
public:
	explicit Slice(const std::filesystem::path& p);
	~Slice() = default;

	Slice(Slice&& other) noexcept = default;
	Slice& operator=(Slice&& other) noexcept = default;

	void processDataset(const std::string& path);
	[[nodiscard]] const float getPixelSpacingX() const { return pixelSpacing.first; }
	[[nodiscard]] const float getPixelSpacingY() const { return pixelSpacing.second; }
	[[nodiscard]] pixel* const getPixels() const { return pixels.get(); }
	[[nodiscard]] const unsigned long getWidth() const { return width; }
	[[nodiscard]] const unsigned long getHeight() const { return height; }
	[[nodiscard]] const space_point getTLHC() const { return tlhc; }
	[[nodiscard]] const std::string getUID() const { return uid; };
	void setPixels(std::unique_ptr<pixel[]> newPxd) { pixels = std::move(newPxd); }
	
	void serialize(const std::filesystem::path& wherePath) const override;

private:
	std::filesystem::path file{ "" };
	std::pair<float, float> pixelSpacing{ 0.0f, 0.0f };
	std::unique_ptr<pixel[]> pixels;
	space_point tlhc{};
	std::string uid;
	unsigned long width{ 0 }, height{ 0 };
};

