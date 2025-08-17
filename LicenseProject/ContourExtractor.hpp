#pragma once

#include "thread_pool.hpp"
#include "IFilter.hpp"

class Slice;

class ContourExtractor : protected thread_pool, 
						 public IFilter
{
public:
	ContourExtractor();
	~ContourExtractor() = default;

	void execute(const std::vector<std::filesystem::path>& paths, workspace& wspace) override;
};

