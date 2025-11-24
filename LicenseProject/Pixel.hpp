#pragma once

#include <cstdint>

class Pixel {
public:
	Pixel(const uint8_t v) : value{ v } {}
	Pixel() : value{ 0 } {}
	~Pixel() = default;

	[[nodiscard]] uint8_t getValue() const { return value; }

	static Pixel MAX() { return Pixel(UINT8_MAX); }
	static Pixel MIN() { return Pixel(0); }

private:
	uint8_t value;
};