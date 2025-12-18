#pragma once

#include "Point2.hpp"
#include "Point3.hpp"
#include "DataInternalRepresentation.hpp"

#include <string>
#include <vector>
#include <utility>

/**
 * .
 */
class PointSet : public DataInternalRepresentation
{
public:
	/**
	 * .
	 * 
	 * \param uid_
	 * \param tlhc_
	 * \param pixSpacingX
	 * \param pixSpacingY
	 */
	PointSet(const Point3& tlhc_, const std::pair<float, float>& pixelSpacing_);

	/**
	 * .
	 * 
	 */
	~PointSet() = default;

	/**
	 * .
	 * 
	 * \param index
	 * \return 
	 */
	[[nodiscard]] Point3 at(const size_t index) const;

	/**
	 * .
	 * 
	 * \param p
	 */
	void insert(const Point2 p);

	/**
	 * .
	 * 
	 * \return 
	 */
	[[nodiscard]] std::string toString2D() const;

	/**
	 * .
	 * 
	 * \return 
	 */
	[[nodiscard]] std::string toString3D() const;

private:
	/**
	 * .
	 */
	const Point3 tlhc;

	/**
	 * .
	 */
	std::pair<float, float> pixelSpacing;

	/**
	 * .
	 */
	std::vector<Point2> points{};
};

