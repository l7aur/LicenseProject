#pragma once

constexpr auto EXIT_THREAD_ALLOCATION_ERROR = -1;

#define MUST_USE_VALUE_ATTR [[nodiscard("You called a getter but did not use the returned value!")]]