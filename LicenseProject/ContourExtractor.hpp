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

	void execute(const std::map<std::filesystem::path, matrix<Settings::pixel>>& m) const override {};
	void saveProgress(const std::string& checkpointPath) const override {};
	bool existsCheckpoint() const override { return true; }
	void loadInput(IFilter* const prevFilter) override {}
	void loadInput(const std::filesystem::path& checkpoint) override {}
};

