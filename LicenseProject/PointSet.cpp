#include "PointSet.hpp"

#include <thread>
#include <fstream>
#include <filesystem>

PointSet::PointSet(const space_point tlhc_, const float pixSpacingX, const float pixSpacingY)
	: tlhc{ tlhc_ }, pixelSpacingX{ pixSpacingX }, pixelSpacingY{ pixSpacingY }
{
}

const space_point PointSet::at(const size_t index) const {
	return space_point{
		.x = tlhc.x + points[index].x,
		.y = tlhc.x + points[index].y,
		.z = tlhc.z
	};
}

void PointSet::add(const image_point p)
{
	points.push_back(p);
}

void PointSet::serialize(const std::filesystem::path& wherePath) const
{
	// TODO fix cache path for an image
	const std::filesystem::path filePath = wherePath / ("pointset_" + std::to_string(std::hash<std::thread::id>{}(std::this_thread::get_id())) + ".txt");
	std::ofstream fout{ filePath };
	fout << points.size() << '\n';
	fout << tlhc.x << ',' << tlhc.y << ',' << tlhc.z << '\n';
	fout << pixelSpacingX << ',' << pixelSpacingY << '\n';
	for (const auto& [x, y] : points)
		fout << x << ',' << y << '\n';
	fout.close();
}
