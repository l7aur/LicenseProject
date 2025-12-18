#pragma once

#include "DataInternalRepresentation.hpp"

#include <typeinfo>
#include <filesystem>
#include <memory>

/**
 * .
 */
class FilterBase {
public:
	/**
	 * .
	 * 
	 * \param _cachePath
	 */
	FilterBase(const std::filesystem::path& _cachePath) : cachePath{ _cachePath } { std::filesystem::create_directories(cachePath); }

	/**
	 * .
	 * 
	 */
	virtual ~FilterBase() = default;

	/**
	 * .
	 * 
	 */
	virtual void loadCache() noexcept(false) = 0;
	
	/**
	 * .
	 * 
	 */
	virtual void cache() noexcept(false) = 0;

	/**
	 * .
	 * 
	 * \return 
	 */
	virtual const std::type_info& inputType() = 0;
	
	/**
	 * .
	 * 
	 * \return 
	 */
	virtual const std::type_info& outputType() = 0;
	
	/**
	 * .
	 * 
	 * \param 
	 * \return 
	 */
	virtual std::unique_ptr<DataInternalRepresentation> apply(DataInternalRepresentation*) noexcept(false) = 0;

	/**
	 * .
	 *
	 * \return
	 */
	[[nodiscard]] const std::filesystem::path& getCachePath() const { return cachePath; }

protected:
	/**
	 * .
	 */
	std::filesystem::path cachePath{ "" };
};