#pragma once

#include "Settings.hpp"

#include <filesystem>
#include <memory>
#include <map>

class Slice;

class IFilter {
public:
	IFilter() = default;
	virtual ~IFilter() = default;

	virtual void execute(std::vector<std::pair<std::filesystem::path, std::unique_ptr<Slice>>>&) = 0;

	const std::filesystem::path getWorkingDir() const { return workingDirectory; }

protected:
	std::filesystem::path workingDirectory;
};