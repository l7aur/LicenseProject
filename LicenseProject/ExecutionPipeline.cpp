#include "ExecutionPipeline.hpp"

ExecutionPipeline::ExecutionPipeline()
	: workspace{ 0 }
{
}

void ExecutionPipeline::executeWithCaching()
{
	for (const auto& currentFilter : filters) {
		workspace.setFilter(currentFilter.get());
		workspace.loadFilterCache();
		workspace.executeFilter();
		workspace.cache();
	}
}

void ExecutionPipeline::execute()
{
	for (const auto& currentFilter : filters) {
		workspace.setFilter(currentFilter.get());
		workspace.executeFilter();
	}
}