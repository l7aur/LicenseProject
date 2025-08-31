#pragma once

#include <memory>
#include <vector>
#include <variant>
#include <cstdint>

class Slice;

using types = std::variant<Slice, int>;
using workspace = std::vector<std::unique_ptr<types>>;
using pixel = uint8_t;