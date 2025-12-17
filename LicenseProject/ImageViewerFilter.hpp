#pragma once

#include "Image.hpp"
#include "Filter.hpp"
#include "DataInternalRepresentation.hpp"

#include <filesystem>
#include <memory>
#include <mutex>

/**
 * .
 */
class ImageViewerFilter : public Filter<Image, Image>
{
public:
	/**
	 * .
	 * 
	 * \param _cachePath
	 */
	ImageViewerFilter(const std::filesystem::path& _cachePath) : Filter{ _cachePath }, mtx{} {}
	
	/**
	 * .
	 * 
	 */
	~ImageViewerFilter() = default;

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
	std::mutex mtx;
};
