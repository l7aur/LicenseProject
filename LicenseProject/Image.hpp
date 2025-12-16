#pragma once

#include "DataInternalRepresentation.hpp"
#include "Pixel.hpp"

#include <opencv2/core/mat.hpp>

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
	 * \param pixels
	 */
	Image(const unsigned int width, const unsigned int height, const Pixel* pixels);
	
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

private:
	cv::Mat img{};
};