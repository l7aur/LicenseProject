#pragma once

#include "IFilter.hpp"
#include "thread_pool.hpp"

class PixelExtractorFilter : public IFilter
{
public:
	PixelExtractorFilter(const std::string_view& cachePath_);

	void execute(const std::vector<std::filesystem::path>& paths, std::vector<workspace>& wspaces) override;
};

