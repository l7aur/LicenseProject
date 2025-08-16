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

	void execute(std::vector<std::pair<std::filesystem::path, std::unique_ptr<Slice>>>& wspace) override;
};

