#pragma once

#include <memory>
#include <variant>
#include <cstdint>

class Slice;
class PointSet;

using types = std::variant<Slice, PointSet>;
using workspace = std::unique_ptr<types>;
using pixel = uint8_t;
#define pixel_max UINT8_MAX

struct space_point { 
	float x{ .0f },
		y{ .0f },
		z{ .0f };
};

struct image_point { 
	unsigned int x{ 0 }, 
		y{ 0 }; 
};
