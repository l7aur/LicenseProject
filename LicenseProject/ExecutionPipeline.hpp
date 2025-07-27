#pragma once

#include "IFilter.hpp"

#include <list>
#include <string>
#include <memory>

class ExecutionPipeline
{
public:
	ExecutionPipeline(const std::string path);
	~ExecutionPipeline() = default;
	ExecutionPipeline(ExecutionPipeline&) = delete;
	void operator=(const ExecutionPipeline&) = delete;

	void addFilter(std::unique_ptr<IFilter> newFilter);
	void setup() const;
	void execute(const bool withCheckpoints = false);

private:
	std::list<std::unique_ptr<IFilter>> filters;
	const std::string rootFolderPath{ "" };
};

