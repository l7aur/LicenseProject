#include "ExecutionPipeline.hpp"

#include <filesystem>

void ExecutionPipeline::addFilter(std::unique_ptr<IFilter> newFilter)
{
	if(newFilter)
		filters.push_back(std::move(newFilter));
}

void ExecutionPipeline::setup()
{
	setPaths();
	matrices.resize(paths.size());
	for (const auto& filter : filters)
		filter->setup();
}

void ExecutionPipeline::executeWithCheckpoints()
{
	IFilter* prevFilter = nullptr;
	for (const auto& currentFilter : filters) {
		currentFilter->loadInput(prevFilter);
		//currentFilter->execute();
		currentFilter->saveProgress("/checkpointPath");

		prevFilter = currentFilter.get();
	}
}

void ExecutionPipeline::executeWithoutCheckpoints()
{
	IFilter* prevFilter = nullptr;
	for (const auto& currentFilter : filters) {
		currentFilter->loadInput(prevFilter);
		//currentFilter->execute();

		prevFilter = currentFilter.get();
	}
}

void ExecutionPipeline::setPaths()
{
	for (const auto& entry : std::filesystem::directory_iterator(rootFolderPath))
		if (entry.is_regular_file())
			paths.push_back(entry.path().string());
}
