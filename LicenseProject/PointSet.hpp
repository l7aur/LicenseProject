#pragma once

#include "Point2.hpp"
#include "Point3.hpp"
#include "DataInternalRepresentation.hpp"

#include <string>
#include <vector>

class PointSet : public DataInternalRepresentation
{
public:

	PointSet(const std::string& uid_, const Point3 tlhc_, const float pixSpacingX, const float pixSpacingY);
	~PointSet() = default;

	[[nodiscard]] Point3 at(const size_t index) const;
	void insert(const Point2 p);

private:
	const std::string uid;
	const Point3 tlhc;
	const float pixelSpacingX, pixelSpacingY;
	std::vector<Point2> points{};
};

