#pragma once

#include "FilterBase.hpp"

#include <list>
#include <memory>
#include <stdexcept>
#include <type_traits>
#include <algorithm>
#include <iostream>
#include <utility>

class Workspace;

/**
 * .
 */
class ExecutionPipeline
{
public:
	/**
	 * .
	 * 
	 * \return 
	 */
	ExecutionPipeline() = default;

	/**
	 * .
	 * 
	 */
	~ExecutionPipeline() = default;

	/**
	 * .
	 * 
	 * \param 
	 */
	ExecutionPipeline(ExecutionPipeline&) = delete;

	/**
	 * .
	 * 
	 * \param 
	 */
	ExecutionPipeline(ExecutionPipeline&&) = delete;

	/**
	 * .
	 * 
	 * \param 
	 */
	void operator=(const ExecutionPipeline&) = delete;

	/**
	 * .
	 * 
	 * \param 
	 */
	void operator=(ExecutionPipeline&&) = delete;

	/**
	 * .
	 */
	template<typename Filter>
	void addFilter(std::unique_ptr<Filter> newFilter) noexcept(false);
	
	/**
	 * .
	 * 
	 * \param value
	 * \return 
	 */
	void setCaching(const bool value = true) noexcept(true) { useCaching = value; }

	/**
	 * .
	 * 
	 * \return 
	 */
	void execute(Workspace& workspace) noexcept(false);

private:
	/**
	 * .
	 */
	std::list<std::unique_ptr<FilterBase>> filters;

	/**
	 * .
	 */
	bool useCaching{ false };

	/**
	 * .
	 * 
	 * \param workspace
	 * \return 
	 */
	void executeWithCaching(Workspace& workspace) noexcept(false);
	
	/**
	 * .
	 * 
	 * \param workspace
	 * \return 
	 */
	void executeWithoutCaching(Workspace& workspace) noexcept(false);
};

template<typename Filter>
inline void ExecutionPipeline::addFilter(std::unique_ptr<Filter> newFilter) noexcept(false)
{
	static_assert(std::is_base_of_v<FilterBase, Filter>, "Filter must inherit from FilterBase");

	if (!newFilter)
		return;

	if (!filters.empty()) {
		FilterBase* lastFilter = filters.back().get();
		if (lastFilter->outputType().hash_code() != newFilter.get()->inputType().hash_code())
			throw std::runtime_error("Input of new filter does not match output of previous filter");
	}

	filters.emplace_back(std::move(newFilter));
}
