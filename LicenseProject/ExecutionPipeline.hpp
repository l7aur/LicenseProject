#pragma once

#include "Workspace.hpp"

#include <list>
#include <memory>
#include "IFilter.hpp"
#include "IFilterBase.hpp"

class ExecutionPipeline
{
public:
	ExecutionPipeline();
	~ExecutionPipeline() = default;
	ExecutionPipeline(ExecutionPipeline&) = delete;
	void operator=(const ExecutionPipeline&) = delete;

	template<typename In, typename Out>
	void addFilter(std::unique_ptr<IFilter<In, Out>> newFilter) {
		if (newFilter)
			filters.push_back(std::make_unique<IFilterBase>(std::move(newFilter)));
	}

	void executeWithCaching();
	void execute();

private:
	Workspace workspace;
	std::list<std::unique_ptr<IFilterBase>> filters{};
};

