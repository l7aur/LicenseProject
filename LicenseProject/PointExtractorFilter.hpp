#pragma once

#include "IFilter.hpp"
#include "thread_pool.hpp"

class PointExtractorFilter : protected thread_pool, 
							 public IFilter
{
public:
	PointExtractorFilter();
	~PointExtractorFilter() = default;

private:
};

