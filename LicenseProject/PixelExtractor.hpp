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
	~PixelExtractor();

	void execute(const std::map<std::filesystem::path, matrix<Settings::pixel>>& paths) const;
	void saveProgress(const std::string& checkpointPath) const override;
	bool existsCheckpoint() const override;
	void loadInput(IFilter* const prevFilter) override;
	void loadInput(const std::filesystem::path& checkpoint) override;

private:
	std::vector<Slice*> series;

	void setupSeries(const std::string& path);
	void populateSeriesWithCheckpoint(const std::string& path);
	void populateSeriesWithoutCheckpoint(const std::string& path);

};

