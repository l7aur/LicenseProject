#pragma once

#include <filesystem>
#include <functional>
#include <memory>

class Slice;

class LocalThresholder
{
public:
	LocalThresholder() = delete;
	~LocalThresholder() = delete;

	static std::function<void()> execute(std::vector<std::pair<std::filesystem::path, std::unique_ptr<Slice>>>& wspace, int index);
};

