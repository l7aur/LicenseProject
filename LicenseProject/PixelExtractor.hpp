#pragma once

#include "thread_pool.hpp"
#include "IFilter.hpp"

class PixelExtractor : public thread_pool, 
					   public IFilter
{
public:
	PixelExtractor();
	~PixelExtractor() = default;

	void execute(const std::vector<std::filesystem::path>& paths, workspace& wspace) override;

private:
};

