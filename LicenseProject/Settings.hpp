#pragma once

#include <memory>
#include <vector>
#include <variant>
#include <cstdint>

class Slice;

using types = std::variant<Slice, int>;
using workspace = std::vector<std::unique_ptr<types>>;
using pixel = uint16_t;

#define PIXEL_MAX static_cast<pixel>(UINT16_MAX)
#define PIXEL_MIN static_cast<pixel>(0)

namespace Settings {
	const bool withCheckpoints{ false };
}