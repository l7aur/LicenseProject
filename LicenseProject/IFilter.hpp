#pragma once

#include "Types.hpp"

#include <vector>
#include <string_view>

namespace std::filesystem { class path; };

class IFilter {
public:
	const std::string_view& getCachePath() const { return cachePath; }

	virtual void execute(const std::vector<std::filesystem::path>&, std::vector<workspace>&) = 0;

protected:
	std::string_view cachePath{ "" };
};