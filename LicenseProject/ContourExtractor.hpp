#pragma once

#include "thread_pool.hpp"
#include "IFilter.hpp"

class Slice;

class ContourExtractor : protected thread_pool, public IFilter
{
public:
	ContourExtractor() = default;
	~ContourExtractor() = default;

private:
	void setup(const std::string&) override {}
	void setup() override {};
	void execute() const override {};
	void saveProgress(const std::string& checkpointPath) const override {};
	bool existsCheckpoint() const override { return true; };
	void loadCheckpoint(const std::string& checkpointPath) override {};

};

