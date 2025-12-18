#pragma once

#include <cstdint>

#include <opencv2/core/hal/interface.h>

using Pixel = uint8_t;

static constexpr inline Pixel PixelMax() { return UINT8_MAX; }
static constexpr inline Pixel PixelMin() { return 0; }

#define PixelCVImageTypeMacro CV_8UC1
