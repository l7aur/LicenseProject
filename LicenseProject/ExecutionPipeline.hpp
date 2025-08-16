#pragma once

#include "Settings.hpp"
#include "IFilter.hpp"
#include "matrix.hpp"

#include <list>
#include <string>
#include <memory>
#include <vector>

class ExecutionPipeline
{
public:
	ExecutionPipeline(const std::string path) : rootFolderPath{ path } {}
	~ExecutionPipeline() = default;
	ExecutionPipeline(ExecutionPipeline&) = delete;
	void operator=(const ExecutionPipeline&) = delete;

	void addFilter(std::unique_ptr<IFilter> newFilter);
	void setup();
	void executeWithCheckpoints();
	void executeWithoutCheckpoints();

private:
	std::vector<matrix<Settings::pixel>> matrices{};
	std::vector<std::string> paths{};
	std::list<std::unique_ptr<IFilter>> filters{};
	const std::string rootFolderPath{ "" };

	void setPaths();
};

