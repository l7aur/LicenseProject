#pragma once

#include "IFilter.hpp"
#include "thread_pool.hpp"

class CannyEdgeDetectorFilter : protected thread_pool,
								public IFilter
{
public:
	CannyEdgeDetectorFilter();
	~CannyEdgeDetectorFilter() = default;

	void execute(const std::vector<std::filesystem::path>&, workspace&) override;
};

