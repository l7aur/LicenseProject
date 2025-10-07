#pragma once

#include "../IFilter.hpp"
#include "thread_pool.hpp"

class PointExtractorFilter : public IFilter
{
public:
	PointExtractorFilter(const std::string_view& cachePath_);
	~PointExtractorFilter() = default;

	void execute(const std::vector<std::filesystem::path>&, std::vector<workspace>&) override;
};

