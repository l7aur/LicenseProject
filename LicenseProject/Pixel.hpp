#pragma once

#include <cstdint>

/**
 * .
 */
class Pixel {
public:
	/**
	 * .
	 * 
	 * \param v
	 */
	Pixel(const uint8_t v) : value{ v } {}
	
	/**
	 * .
	 * 
	 */
	Pixel() : value{ 0 } {}
	
	/**
	 * .
	 * 
	 */
	~Pixel() = default;

	/**
	 * .
	 * 
	 * \return 
	 */
	[[nodiscard]] uint8_t getValue() const { return value; }

	/**
	 * .
	 * 
	 * \return 
	 */
	static Pixel MAX() { return Pixel(UINT8_MAX); }
	
	/**
	 * .
	 * 
	 * \return 
	 */
	static Pixel MIN() { return Pixel(0); }

private:
	/**
	 * .
	 */
	uint8_t value;
};