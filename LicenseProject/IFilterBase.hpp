#pragma once

#include "DataInternalRepresentation.hpp"

#include <typeinfo>
#include <filesystem>
#include <memory>

/**
 * .
 */
class IFilterBase {
public:
	/**
	 * .
	 * 
	 * \param _cachePath
	 */
	IFilterBase(const std::filesystem::path& _cachePath) : cachePath{ _cachePath } {}

	/**
	 * .
	 * 
	 */
	virtual ~IFilterBase() = default;

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
	virtual std::unique_ptr<DataInternalRepresentation> apply(const DataInternalRepresentation*) noexcept(false) = 0;

	/**
	 * .
	 *
	 * \return
	 */
	const std::filesystem::path& getCachePath() const { return cachePath; }

private:
	/**
	 * .
	 */
	std::filesystem::path cachePath{ "" };
};