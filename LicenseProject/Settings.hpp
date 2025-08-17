#pragma once

#include <memory>
#include <vector>
#include <variant>
#include <cstdint>

class Slice;

using types = std::variant<Slice, int>;
using workspace = std::vector<std::unique_ptr<types>>;
using pixel = uint16_t;

#define pixel_max UINT16_MAX
#define pixel_min 0

namespace Settings {
	const bool withCheckpoints{ false };
}