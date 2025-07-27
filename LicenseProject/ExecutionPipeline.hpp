#pragma once

#include "IFilter.hpp"

#include <list>
#include <memory>

class ExecutionPipeline
{
public:
	ExecutionPipeline() = default;
	~ExecutionPipeline() = default;
	ExecutionPipeline(ExecutionPipeline&) = delete;
	void operator=(const ExecutionPipeline&) = delete;

	void addFilter(std::unique_ptr<IFilter> newFilter);
	void execute(const bool withCheckpoints = false);

private:
	std::list<std::unique_ptr<IFilter>> filters;
};

