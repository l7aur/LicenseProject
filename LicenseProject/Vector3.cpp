#include "Vector3.hpp"

Vector3::Vector3(const double dX, const double dY, const double dZ)
	: Point3{ dX, dY, dZ }
{
}

double Vector3::dot(const Vector3& other) const
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vector3 Vector3::cross(const Vector3& other) const
{
	return Vector3(
		this->y * other.z - this->z * other.y,
		this->z * other.x - this->x * other.z,
		this->x * other.y - this->y * other.x);
}
