#pragma once

#include "Types.hpp"
#include "IWorkspace.hpp"

#include <vector>

class PointSet : public IWorkspace
{
public:

	PointSet(const space_point tlhc_, const float pixSpacingX, const float pixSpacingY);
	~PointSet() = default;

	[[nodiscard]] const space_point at(const size_t index) const;
	void add(const image_point p);
	void serialize(const std::filesystem::path& wherePath) const override;

private:
	const space_point tlhc;
	const float pixelSpacingX, pixelSpacingY;
	std::vector<image_point> points{};
};

