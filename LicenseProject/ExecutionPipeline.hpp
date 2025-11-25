#pragma once

#include "Workspace.hpp"
#include "IFilterBase.hpp"

#include <list>
#include <memory>
#include <stdexcept>
#include <type_traits>

class ExecutionPipeline
{
public:
	ExecutionPipeline() noexcept(true);
	~ExecutionPipeline() = default;
	ExecutionPipeline(ExecutionPipeline&) = delete;
	ExecutionPipeline(ExecutionPipeline&&) = delete;
	void operator=(const ExecutionPipeline&) = delete;
	void operator=(ExecutionPipeline&&) = delete;

	/**
	* 
	*/
	template<typename Filter>
	void addFilter(std::unique_ptr<Filter> newFilter) noexcept(false);
	
	/**
	*
	*/
	void setCaching(const bool value = true) noexcept(true) { useCaching = value; }

	/**
	*
	*/
	void execute() noexcept(false);

private:
	Workspace workspace;
	std::list<std::unique_ptr<IFilterBase>> filters;
	bool useCaching{ false };

	void executeWithCaching() noexcept(false);
	void executeWithoutCaching() noexcept(false);
};

template<typename Filter>
inline void ExecutionPipeline::addFilter(std::unique_ptr<Filter> newFilter) noexcept(false)
{
	static_assert(std::is_base_of_v<IFilterBase, Filter>, "Filter must inherit from IFilterBase");

	if (!newFilter)
		return;

	if (!filters.empty()) {
		IFilterBase* lastFilter = filters.back().get();
		if (lastFilter->outputType() != typeid(newFilter.get()->inputType()))
			throw std::runtime_error("Input of new filter does not match output of previous filter");
	}

	filters.push_back(std::move(newFilter));
}
