#include "PointSet.hpp"

PointSet::PointSet(const std::string& uid_, const Point3 tlhc_, const float pixSpacingX, const float pixSpacingY)
	: uid{uid_}, tlhc{ tlhc_ }, pixelSpacingX{ pixSpacingX }, pixelSpacingY{ pixSpacingY }
{
}

Point3 PointSet::at(const size_t index) const {
	return Point3(
		tlhc.getX() + points.at(index).getX(),
		tlhc.getY() + points.at(index).getY(),
		tlhc.getZ()
	);
}

void PointSet::insert(const Point2 p)
{
	points.push_back(p);
}

//void PointSet::serialize(const std::filesystem::path& wherePath) const
//{
//	const std::filesystem::path filePath = wherePath / (uid + ".txt");
//	std::ofstream fout{ filePath };
//	fout << points.size() << '\n';
//	fout << tlhc.x << ',' << tlhc.y << ',' << tlhc.z << '\n';
//	fout << pixelSpacingX << ',' << pixelSpacingY << '\n';
//	for (const auto& [x, y] : points)
//		fout << x << ',' << y << '\n';
//	fout.close();
//}
