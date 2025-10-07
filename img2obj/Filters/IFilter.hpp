#pragma once

#include "Types.hpp"
#include "thread_pool.hpp"

#include <vector>
#include <string_view>

namespace std::filesystem { class path; };

class IFilter : public thread_pool {
public:
	virtual ~IFilter() = default; 
	const std::string_view& getCachePath() const { return cachePath; }

	virtual void execute(const std::vector<std::filesystem::path>&, std::vector<workspace>&) = 0;

protected:
	std::string_view cachePath{ "" };
};