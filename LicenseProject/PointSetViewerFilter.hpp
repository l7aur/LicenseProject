#pragma once

#include "Filter.hpp"
#include "PointSet.hpp"
#include "DataInternalRepresentation.hpp"

#include <filesystem>
#include <memory>
#include <mutex>

/**
 * .
 */
class PointSetViewerFilter : public Filter<PointSet, PointSet>
{
public:
	/**
	 * .
	 * 
	 * \param _cache
	 */
	PointSetViewerFilter(const std::filesystem::path& _cachePath);
	
	/**
	 * .
	 * 
	 */
	~PointSetViewerFilter() = default;

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
