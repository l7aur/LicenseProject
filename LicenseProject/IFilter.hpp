#pragma once

#include "Settings.hpp"

#include <filesystem>
#include <map>

class Slice;

class IFilter {
public:
	IFilter() = default;
	virtual ~IFilter() = default;

	virtual void execute(const std::vector<std::filesystem::path>&, workspace&) = 0;

	const std::filesystem::path getWorkingDir() const { return workingDirectory; }

protected:
	std::filesystem::path workingDirectory;
};