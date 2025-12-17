#include "Filter.hpp"
#include "Image.hpp"
#include "DataInternalRepresentation.hpp"

#include <memory>
#include <filesystem>
#include <opencv2/imgproc.hpp>

/**
 * .
 */
class OpeningFilter : public Filter<Image, Image>
{
public:
	/**
	 * .
	 * 
	 * \param _structuringElementWidth
	 * \param _structuringElementHeight
	 * \param _structuringElementShape
	 * \param _cachePath
	 */
	OpeningFilter(
		const unsigned int _structuringElementWidth,
		const unsigned int _structuringElementHeight,
		cv::MorphShapes _structuringElementShape,
		const std::filesystem::path& _cachePath);
	
	/**
	 * .
	 * 
	 */
	~OpeningFilter() = default;

	/**
	* .
	*
	*/
	void loadCache() override;

	/**
	 * .
	 *
	 */
	void cache() override;

	/**
	 * .
	 *
	 * \param input
	 * \return
	 */
	std::unique_ptr<DataInternalRepresentation> process(input_type* input) noexcept(false) override;

private:
	/**
	 * .
	 */
	const unsigned int structuringElementWidth;

	/**
	 * .
	 */
	const unsigned int structuringElementHeight;

	/**
	 * .
	 */
	cv::MorphShapes structuringElementShape;
};