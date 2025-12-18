#pragma once

#include "Pixel.hpp"
#include "Point3.hpp"
#include "DataInternalRepresentation.hpp"

#include <memory>
#include <string>
#include <utility>
#include <filesystem>
#include <vector>

/**
 * .
 */
class Slice : public DataInternalRepresentation
{
public:
	/**
	 * .
	 * 
	 * \param p
	 */
	explicit Slice(const std::filesystem::path& p);

	/**
	 * .
	 * 
	 */
	~Slice() = default;	

	/**
	 * .
	 *
	 * \param other
	 * \return
	 */
	Slice(Slice&& other) noexcept = delete;

	/**
	 * .
	 *
	 * \param other
	 * \return
	 */
	Slice& operator=(Slice&& other) noexcept = delete;

	/**
	 * .
	 * 
	 * \param path
	 */
	void processDataset(const std::string& path);
	
	/**
	 * .
	 * 
	 * \return 
	 */
	[[nodiscard]] std::pair<float, float> getPixelSpacing() const { return pixelSpacing; }

	/**
	 * .
	 * 
	 * \return 
	 */
	[[nodiscard]] const std::vector<Pixel>* const getPixels() const { return pixels.get(); }

	/**
	 * .
	 * 
	 * \return 
	 */
	[[nodiscard]] unsigned long getWidth() const { return width; }

	/**
	 * .
	 * 
	 * \return 
	 */
	[[nodiscard]] unsigned long getHeight() const { return height; }

	/**
	 * .
	 * 
	 * \return 
	 */
	[[nodiscard]] Point3 getTLHC() const { return tlhc; }

	/**
	 * .
	 */
	[[nodiscard]] std::string getUID() const { return uid; };

	/**
	 * .
	 * 
	 * \param newPxd
	 */
	void setPixels(std::unique_ptr<std::vector<Pixel>> newPxd) { pixels = std::move(newPxd); }
	
private:
	/**
	 * .
	 */
	std::filesystem::path file{ "" };
	
	/**
	 * .
	 */
	std::pair<float, float> pixelSpacing{ 0.0f, 0.0f };
	
	/**
	 * .
	 */
	std::unique_ptr<std::vector<Pixel>> pixels;
	
	/**
	 * .
	 */
	Point3 tlhc{};
	
	/**
	 * .
	 */
	std::string uid;

	/**
	 * .
	 */
	unsigned long width{ 0 }, height{ 0 };
};