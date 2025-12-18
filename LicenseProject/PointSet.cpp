#include "PointSet.hpp"
#include "Point2.hpp"
#include "Point3.hpp"

#include <utility>
#include <string>
#include <algorithm>

PointSet::PointSet(const Point3& tlhc_, const std::pair<float, float>& pixelSpacing_)
	: tlhc{ tlhc_ }, pixelSpacing{ pixelSpacing_ }
{
}

Point3 PointSet::at3D(const size_t index) const {
	return Point3(
		tlhc.getX() + points.at(index).getX(),
		tlhc.getY() + points.at(index).getY(),
		tlhc.getZ()
	);
}

Point2 PointSet::at2D(const size_t index) const {
	return points.at(index);
}

void PointSet::insert(const Point2& p)
{
	points.push_back(p);
}

std::string PointSet::toString2D() const
{
	std::string out{ "----- PointSet 2D -----\n\n" };
	std::for_each(points.begin(), points.end(), [&out](const Point2& p) {
		out += "[";
		out += std::to_string(p.getX());
		out += "; ";
		out += std::to_string(p.getY());
		out += "]\n";
		});

	return out.append("\n");
}

std::string PointSet::toString3D() const
{
	std::string out{ "----- PointSet 3D -----\n\n" };
	std::for_each(points.begin(), points.end(), [&out, _tlhc = tlhc](const Point2& p) {
		out += "[";
		out += std::to_string(p.getX() + _tlhc.getX());
		out += "; ";
		out += std::to_string(p.getY() + _tlhc.getY());
		out += "; ";
		out += std::to_string(_tlhc.getZ());
		out += "]\n";
		});

	return out.append("\n");
}