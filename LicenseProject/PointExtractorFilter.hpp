#pragma once

#include "IFilter.hpp"
#include "Slice.hpp"
#include "PointSet.hpp"

#include <filesystem>

class PointExtractorFilter : public IFilter<Slice, PointSet>
{
public:
	PointExtractorFilter(const std::filesystem::path& _cachePath) { cachePath = _cachePath; }
	~PointExtractorFilter() = default;

	void loadCache() override;
	void cache() override;
};

