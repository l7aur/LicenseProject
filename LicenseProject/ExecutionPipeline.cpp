#include "ExecutionPipeline.hpp"

ExecutionPipeline::ExecutionPipeline() noexcept(true)
	: workspace{ 0 }
{
}

void ExecutionPipeline::execute() noexcept(false)
{
	if (useCaching)
		executeWithCaching();
	else
		executeWithoutCaching();
}

/**
 * .
 * 
 * \return 
 */
void ExecutionPipeline::executeWithCaching() noexcept(false)
{
	for (const auto& currentFilter : filters) {
		workspace.setFilter(currentFilter.get());
		workspace.loadFilterCache();
		workspace.executeFilter();
		workspace.cache();
	}
}

/**
 * .
 * 
 * \return 
 */
void ExecutionPipeline::executeWithoutCaching() noexcept(false)
{
	for (const auto& currentFilter : filters) {
		workspace.setFilter(currentFilter.get());
		workspace.executeFilter();
	}
}