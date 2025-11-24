#pragma once

#include "Point3.hpp"

class Vector3 : private Point3 {
public:
	Vector3(const double dX, const double dY, const double dZ);
	~Vector3() = default;

	[[nodiscard]] double getX() const { return this->getX(); }
	[[nodiscard]] double getY() const { return this->getY(); }
	[[nodiscard]] double getZ() const { return this->getZ(); }

	double dot(const Vector3& other) const;
	Vector3 cross(const Vector3& other) const;
};