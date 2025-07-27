#pragma once

#include "thread_pool.hpp"
#include "IFilter.hpp"

#include <vector>
#include <string>

class Slice;

class PixelExtractor : public thread_pool, public IFilter
{
public:
	PixelExtractor();
	~PixelExtractor();

	void setup(const std::string& workingDirectoryPath) override;
	void execute() const override;
	void saveProgress(const std::string& checkpointPath) const override;
	bool existsCheckpoint() const override;
	void loadCheckpoint(const std::string& checkpointPath) override;

private:
	std::vector<Slice*> series;

	inline static std::string CHECKPOINT_PATH{ ".\\checkpoint\\preprocessing\\" };

	void setupSeries(const std::string& path);
	void populateSeriesWithCheckpoint(const std::string& path);
	void populateSeriesWithoutCheckpoint(const std::string& path);

};

