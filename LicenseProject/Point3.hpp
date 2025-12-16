#pragma once

/**
 * .
 */
class Point3 {
public:
	/**
	 * .
	 * 
	 * \param _x
	 * \param _y
	 * \param _z
	 */
	Point3(const double _x, const double _y, const double _z);
	
	/**
	 * .
	 * 
	 */
	Point3();
	
	/**
	 * .
	 * 
	 */
	~Point3() = default;

	/**
	 * .
	 * 
	 * \return 
	 */
	[[nodiscard]] double getX() const { return x; }
	
	/**
	 * .
	 * 
	 * \return 
	 */
	[[nodiscard]] double getY() const { return y; }
	
	/**
	 * .
	 * 
	 * \return 
	 */
	[[nodiscard]] double getZ() const { return z; }

protected:
	/**
	 * .
	 */
	double x{ 0.0 };
	
	/**
	 * .
	 */
	double y{ 0.0 };
	
	/**
	 * .
	 */
	double z{ 0.0 };
};