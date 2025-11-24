#pragma once

#include "IFilter.hpp"
#include "Slice.hpp"
#include "Path.hpp"

#include <filesystem>

class PixelExtractorFilter : public IFilter<Path, Slice>
{
public:
	PixelExtractorFilter(const std::filesystem::path& _cachePath) { cachePath = _cachePath; }
	~PixelExtractorFilter() = default;

	void loadCache() override;
	void cache() override;
};

