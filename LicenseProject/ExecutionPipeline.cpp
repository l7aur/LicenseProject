#include "ExecutionPipeline.hpp"

ExecutionPipeline::ExecutionPipeline(const std::string path)
	: rootFolderPath{ path }
{
}

void ExecutionPipeline::addFilter(std::unique_ptr<IFilter> newFilter)
{
	if(newFilter)
		filters.push_back(std::move(newFilter));
}

void ExecutionPipeline::setup() const
{
	for (const auto& filter : filters)
		filter->setup(rootFolderPath);
}

void ExecutionPipeline::execute(const bool withCheckpoints)
{
	IFilter* prevFilter = nullptr;
	for (const auto& currentFilter : filters) {
		if (withCheckpoints && currentFilter->existsCheckpoint()) {
			prevFilter = currentFilter.get();
			continue;
		}

		if (withCheckpoints && prevFilter != nullptr)
			prevFilter->loadCheckpoint("test");

		currentFilter->execute();

		if (withCheckpoints)
			currentFilter->saveProgress("test");
	}
}
