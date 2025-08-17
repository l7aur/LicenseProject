#pragma once

#include "Settings.hpp"

#include <filesystem>
#include <functional>

class Slice;

class LocalThresholder
{
public:
	LocalThresholder() = delete;
	~LocalThresholder() = delete;

	static std::function<void()> execute(workspace& wspace, size_t index);
};

