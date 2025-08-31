#pragma once

#include "Slice.hpp"
#include "PointSet.hpp"

#include <list>
#include <vector>
#include <string>
#include <filesystem>

class IFilter;

class ExecutionPipeline
{
public:
	ExecutionPipeline(const std::filesystem::path seriesPath_);
	~ExecutionPipeline() = default; // TODO crashes at end of execution
	ExecutionPipeline(ExecutionPipeline&) = delete;
	void operator=(const ExecutionPipeline&) = delete;

	void addFilter(std::unique_ptr<IFilter> newFilter);
	void executeWithCaching();
	void execute();
	void display() const;

private:
	std::vector<workspace> wspaces;
	std::vector<std::filesystem::path> paths;
	std::list<std::unique_ptr<IFilter>> filters{};
	const std::filesystem::path seriesPath;

	void cache(const std::string_view& cachePath) const;
};

