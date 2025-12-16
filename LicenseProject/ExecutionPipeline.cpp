#include "ExecutionPipeline.hpp"
#include "Workspace.hpp"

void ExecutionPipeline::execute(Workspace& workspace) noexcept(false)
{
	if (useCaching)
		executeWithCaching(workspace);
	else
		executeWithoutCaching(workspace);
}

void ExecutionPipeline::executeWithCaching(Workspace& workspace) noexcept(false)
{
	for (const auto& currentFilter : filters) {
		workspace.setFilter(currentFilter.get());
		workspace.loadFilterCache();
		workspace.executeFilter();
		workspace.cache();
	}
}

void ExecutionPipeline::executeWithoutCaching(Workspace& workspace) noexcept(false)
{
	for (const auto& currentFilter : filters) {
		workspace.setFilter(currentFilter.get());
		workspace.executeFilter();
	}
}