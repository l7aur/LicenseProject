#pragma once

#include "Point3.hpp"

/**
 * .
 */
class Vector3 : private Point3 {
public:
	/**
	 * .
	 * 
	 * \param dX
	 * \param dY
	 * \param dZ
	 */
	Vector3(const double dX, const double dY, const double dZ);
	
	/**
	 * .
	 * 
	 */
	~Vector3() = default;

	/**
	 * .
	 * 
	 * \return 
	 */
	[[nodiscard]] double getX() const { return this->getX(); }
	
	/**
	 * .
	 * 
	 * \return 
	 */
	[[nodiscard]] double getY() const { return this->getY(); }
	
	/**
	 * .
	 * 
	 * \return 
	 */
	[[nodiscard]] double getZ() const { return this->getZ(); }

	/**
	 * .
	 * 
	 * \param other
	 * \return 
	 */
	double dot(const Vector3& other) const;
	
	/**
	 * .
	 * 
	 * \param other
	 * \return 
	 */
	Vector3 cross(const Vector3& other) const;
};