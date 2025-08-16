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

private:
};

