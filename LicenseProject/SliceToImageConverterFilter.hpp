#pragma once

#include "Filter.hpp"
#include "DataInternalRepresentation.hpp"
#include "Slice.hpp"
#include "Image.hpp"

#include <filesystem>
#include <memory>

/**
 * .
 */
class SliceToImageConverterFilter : public Filter<Slice, Image>
{
public:
	/**
	 * .
	 * 
	 */
	SliceToImageConverterFilter(const std::filesystem::path& _cachePath) : Filter{ _cachePath } {}

	/**
	 * .
	 * 
	 */
	~SliceToImageConverterFilter() = default;

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
};
