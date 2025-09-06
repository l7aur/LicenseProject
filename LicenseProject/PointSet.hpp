#pragma once

#include "Types.hpp"
#include "IWorkspace.hpp"

#include <string>
#include <vector>

class PointSet : public IWorkspace
{
public:

	PointSet(const std::string& uid_, const space_point tlhc_, const float pixSpacingX, const float pixSpacingY);
	~PointSet() = default;

	[[nodiscard]] const space_point at(const size_t index) const;
	void add(const image_point p);
	void serialize(const std::filesystem::path& wherePath) const override;

private:
	const std::string uid;
	const space_point tlhc;
	const float pixelSpacingX, pixelSpacingY;
	std::vector<image_point> points{};
};

