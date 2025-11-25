#pragma once

#include "DataInternalRepresentation.hpp"
#include "thread_pool.hpp"
#include "IFilterBase.hpp"

#include <vector>
#include <memory>

/**
 * .
 */
class Workspace : private thread_pool 
{
public:
	/**
	 * .
	 * 
	 * \param numberOfElemets
	 */
	Workspace(const size_t numberOfElemets);
	/**
	 * .
	 * 
	 */
	~Workspace() = default;

	/**
	 * .
	 * 
	 */
	template<typename T>
	T* at(const size_t index) const { return dynamic_cast<T*>(internalRepresentation.at(index).get()); }
	
	/**
	 * .
	 * 
	 * \param filter
	 */
	void setFilter(IFilterBase* filter) { currentFilter = filter; }

	/**
	 * .
	 * 
	 */
	void loadFilterCache() { currentFilter->loadCache(); }

	/**
	 * .
	 * 
	 */
	void cache() const { currentFilter->cache(); }

	/**
	 * .
	 * 
	 */
	void executeFilter();

private:
	/**
	 * .
	 */
	std::vector<std::unique_ptr<DataInternalRepresentation>> internalRepresentation;

	/**
	 * .
	 */
	IFilterBase* currentFilter;
};