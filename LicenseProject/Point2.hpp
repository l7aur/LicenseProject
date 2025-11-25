#pragma once

/**
 * .
 */
class Point2 {
public:
	/**
	 * .
	 * 
	 * \param _x
	 * \param _y
	 */
	Point2(const double _x, const double _y);
	
	/**
	 * .
	 * 
	 */
	Point2();
	
	/**
	 * .
	 * 
	 */
	~Point2() = default;

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

private:
	/**
	 * .
	 */
	double x;
	
	/**
	 * .
	 */
	double y;
};