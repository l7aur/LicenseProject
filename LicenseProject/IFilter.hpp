#pragma once

#include "Types.hpp"

#include <string_view>

namespace std::filesystem { class path; };

class IFilter {
public:
	IFilter() = default;
	virtual ~IFilter() = default;

	virtual void execute(const std::vector<std::filesystem::path>&, workspace&) = 0;

	const std::string_view& getCachePath() const { return cachePath; }

protected:
	std::string_view cachePath;
};