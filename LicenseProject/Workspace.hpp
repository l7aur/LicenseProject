#pragma once

#include "DataInternalRepresentation.hpp"
#include "thread_pool.hpp"
#include "FilterBase.hpp"

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
	void setFilter(FilterBase* filter) { currentFilter = filter; }

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
	 * Assume `internalRepresentation` vector does not resize.
	 * Assume one thread has access to a single slot in the `internalRepresentation` vector at once.
	 * Assume `currentFilter` is not dangling.
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
	FilterBase* currentFilter; // todo think about making this shared_ptr so that it cannot be released before executeFilter is done
};