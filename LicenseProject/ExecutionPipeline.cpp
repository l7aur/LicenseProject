#include "ExecutionPipeline.hpp"
#include "IFilter.hpp"

ExecutionPipeline::ExecutionPipeline(const std::filesystem::path dir)
	: directory{ dir } 
{
	for (const auto& entry : std::filesystem::directory_iterator(directory))
		if (entry.is_regular_file())
			paths.push_back(entry.path());
	wspace.resize(paths.size());
}

void ExecutionPipeline::addFilter(std::unique_ptr<IFilter> newFilter)
{
	if(newFilter)
		filters.push_back(std::move(newFilter));
}

void ExecutionPipeline::executeWithCheckpoints()
{
	for (const auto& currentFilter : filters) {
		//loadInput(prevFilter);
		currentFilter->execute(paths, wspace);
		//saveProgress("/checkpointPath");
	}
}

void ExecutionPipeline::executeWithoutCheckpoints()
{
	for (const auto& currentFilter : filters)
		currentFilter->execute(paths, wspace);
}
