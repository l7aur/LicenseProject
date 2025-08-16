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

	virtual void setup() {}
	virtual void execute(std::vector<std::pair<std::filesystem::path, std::unique_ptr<Slice>>>&) = 0;
	virtual void saveProgress(const std::string&) const = 0;
	virtual bool existsCheckpoint() const = 0;
	virtual void loadInput(IFilter* const prevFilter) = 0;

	const std::filesystem::path getWorkingDir() const { return workingDirectory; }

protected:
	std::filesystem::path workingDirectory;
};