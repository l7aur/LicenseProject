#pragma once

class Point2 {
public:
	Point2(const double _x, const double _y);
	Point2();
	~Point2() = default;

	[[nodiscard]] double getX() const { return x; }
	[[nodiscard]] double getY() const { return y; }

private:
	double x;
	double y;
};