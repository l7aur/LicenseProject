#pragma once

#include "Settings.hpp"
#include "matrix.hpp"

#include <filesystem>
#include <memory>
#include <map>

class IFilter {
public:
	IFilter() = default;
	virtual ~IFilter() = default;

	virtual void setup() {}
	virtual void execute(const std::map<std::filesystem::path, matrix<Settings::pixel>>&) const = 0;
	virtual void saveProgress(const std::string&) const = 0;
	virtual bool existsCheckpoint() const = 0;
	virtual void loadInput(IFilter* const prevFilter) = 0;
	virtual void loadInput(const std::filesystem::path& checkpoint) = 0;

	const std::filesystem::path getWorkingDir() const { return workingDirectory; }

protected:
	std::filesystem::path workingDirectory;
};