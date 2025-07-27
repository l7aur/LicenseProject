#pragma once

#include "thread_pool.hpp"
#include "IFilter.hpp"

class Slice;

class EdgeExtractor : protected thread_pool, public IFilter
{
public:
	EdgeExtractor() = default;
	~EdgeExtractor() = default;

private:
	void setup(const std::string& workingDirectoryPath) override {};
	void execute() const override {};
	void saveProgress(const std::string& checkpointPath) const override {};
	bool existsCheckpoint() const override { return true; };
	void loadCheckpoint(const std::string& checkpointPath) override {};

};

