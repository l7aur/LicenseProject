#pragma once

#include "IFilter.hpp"
#include "thread_pool.hpp"

class PixelExtractorFilter : protected thread_pool, 
							 public IFilter
{
public:
	PixelExtractorFilter();
	~PixelExtractorFilter() = default;

	void execute(const std::vector<std::filesystem::path>& paths, workspace& wspace) override;

private:
};

