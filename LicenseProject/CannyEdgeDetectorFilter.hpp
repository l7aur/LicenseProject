#pragma once

#include "IFilter.hpp"
#include "thread_pool.hpp"

class CannyEdgeDetectorFilter : protected thread_pool,
								public IFilter
{
public:
	CannyEdgeDetectorFilter(
		const int minIntensity,
		const int maxIntensity,
		const int apertureSize_,
		const bool accurateGrad,
		const std::string_view& cachePath_
	);
	~CannyEdgeDetectorFilter() = default;

	void execute(const std::vector<std::filesystem::path>&, workspace&) override;
	
private:
	const int minimumIntensity, maximumIntensity;
	const int apertureSize;
	const bool useMoreAccurateGradient;
};

