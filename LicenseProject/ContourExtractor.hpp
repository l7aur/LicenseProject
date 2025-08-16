#pragma once

#include "thread_pool.hpp"
#include "IFilter.hpp"

class Slice;

class ContourExtractor : protected thread_pool, 
						 public IFilter
{
public:
	ContourExtractor() = default;
	~ContourExtractor() = default;

	void execute(std::vector<std::pair<std::filesystem::path, std::unique_ptr<Slice>>>& m) override {};
	void saveProgress(const std::string& checkpointPath) const override {};
	bool existsCheckpoint() const override { return true; }
	void loadInput(IFilter* const prevFilter) override {}
};

