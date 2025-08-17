#pragma once

#include "Settings.hpp"
#include "Slice.hpp"

#include <list>
#include <string>
#include <filesystem>

class IFilter;

class ExecutionPipeline
{
public:
	ExecutionPipeline(const std::filesystem::path dir);
	~ExecutionPipeline() = default;
	ExecutionPipeline(ExecutionPipeline&) = delete;
	void operator=(const ExecutionPipeline&) = delete;

	void addFilter(std::unique_ptr<IFilter> newFilter);
	void executeWithCheckpoints();
	void executeWithoutCheckpoints();

private:
	workspace wspace;
	std::vector<std::filesystem::path> paths;
	std::list<std::unique_ptr<IFilter>> filters{};
	const std::filesystem::path directory{ "" };
};

