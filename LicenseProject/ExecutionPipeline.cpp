#include "ExecutionPipeline.hpp"

#include <filesystem>

ExecutionPipeline::ExecutionPipeline(const std::filesystem::path dir)
	: directory{ dir } 
{
	for (const auto& entry : std::filesystem::directory_iterator(directory))
		if (entry.is_regular_file())
			workspace.push_back({ entry.path(), nullptr });
}

void ExecutionPipeline::addFilter(std::unique_ptr<IFilter> newFilter)
{
	if(newFilter)
		filters.push_back(std::move(newFilter));
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
		currentFilter->execute(workspace);

		prevFilter = currentFilter.get();
	}
}
