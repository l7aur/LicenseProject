#include "Filter.hpp"
#include "Image.hpp"
#include "DataInternalRepresentation.hpp"

#include <memory>
#include <filesystem>
#include <opencv2/imgproc.hpp>

/**
 * .
 */
class MorphologicalFilter : public Filter<Image, Image>
{
public:
	/**
	 * .
	 * 
	 * \param _structuringElementWidth
	 * \param _structuringElementHeight
	 * \param _structuringElementShape
	 * \param _morphologicalType
	 * \param _cachePath
	 */
	MorphologicalFilter(
		const unsigned int _structuringElementWidth,
		const unsigned int _structuringElementHeight,
		cv::MorphShapes _structuringElementShape,
		cv::MorphTypes _morphologicalType,
		const std::filesystem::path& _cachePath);
	
	/**
	 * .
	 * 
	 */
	~MorphologicalFilter() = default;

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

	/**
	 * .
	 */
	cv::MorphTypes morphologicalType;
};