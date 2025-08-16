#pragma once

#include "thread_pool.hpp"
#include "IFilter.hpp"

#include <vector>
#include <string>

class Slice;

class PixelExtractor : public thread_pool, 
					   public IFilter
{
public:
	PixelExtractor();
	~PixelExtractor() = default;

	void execute(std::vector<std::pair<std::filesystem::path, std::unique_ptr<Slice>>>& wspace);
	void saveProgress(const std::string& checkpointPath) const override;
	bool existsCheckpoint() const override;
	void loadInput(IFilter* const prevFilter) override;

private:
	void setupSeries(const std::string& path);
	void populateSeriesWithCheckpoint(const std::string& path);
	void populateSeriesWithoutCheckpoint(const std::string& path);

};

