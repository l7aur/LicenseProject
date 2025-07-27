#pragma once

#include <vector>
#include <string>
#include "thread_pool.hpp"

class Slice;

class PixelExtractor : public thread_pool
{
public:
	PixelExtractor(const std::string& path, const bool createCheckpoint);
	~PixelExtractor();

private:
	std::vector<Slice*> series;

	inline static std::string CHECKPOINT_PATH{ ".\\checkpoint\\preprocessing\\" };

	void setupSeries(const std::string& path);
	void populateSeriesWithCheckpoint(const std::string& path);
	void populateSeriesWithoutCheckpoint(const std::string& path);

};

