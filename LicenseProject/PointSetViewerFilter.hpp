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
	 */
	enum Type { _2D, _3D };

	/**
	 * .
	 * 
	 * \param t
	 * \param _cachePath
	 */
	PointSetViewerFilter(const Type t, const std::filesystem::path& _cachePath);
	
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
	Type viewType;
};
