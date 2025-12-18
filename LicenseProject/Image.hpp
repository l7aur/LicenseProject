#pragma once

#include "DataInternalRepresentation.hpp"
#include "Pixel.hpp"
#include "Point3.hpp"

#include <opencv2/core/mat.hpp>
#include <utility>

/**
 * .
 */
class Image : public DataInternalRepresentation 
{
public:
	/**
	 * .
	 * 
	 */
	Image() = default;

	/**
	 * .
	 * 
	 * \param width
	 * \param height
	 * \param _pixelSpacing
	 * \param _tlhc
	 * \param pixels
	 */
	Image(
		const unsigned int width, 
		const unsigned int height,
		const std::pair<float, float> _pixelSpacing,
		const Point3 _tlhc,
		const Pixel* pixels);
	
	/**
	 * .
	 * 
	 */
	~Image() = default;

	/**
	 * .
	 */
	const cv::Mat& getImage() const { return img; };

	/**
	 * .
	 * 
	 * \return 
	 */
	cv::Mat& imageHandle() { return img; }

	/**
	 * .
	 * 
	 * \return 
	 */
	const std::pair<float, float>& getPixelSpacing() const { return pixelSpacing; }

	/**
	 * .
	 * 
	 * \return 
	 */
	const Point3& getTLHC() const { return tlhc; }

	/**
	 * .
	 * 
	 * \return 
	 */
	const int getWidth() const { return img.cols; }
	
	/**
	 * .
	 * 
	 * \return 
	 */
	const int getHeight() const { return img.rows; }

	const Pixel& at(int i, int j) const { return img.at<Pixel>(i, j); }

private:
	cv::Mat img{};
	const std::pair<float, float> pixelSpacing{ 1.0f, 1.0f };
	const Point3 tlhc{};
};