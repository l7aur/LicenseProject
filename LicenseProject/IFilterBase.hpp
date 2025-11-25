#pragma once

#include "DataInternalRepresentation.hpp"

#include <typeinfo>
#include <memory>

/**
 * .
 */
class IFilterBase {
public:
	/**
	 * .
	 * 
	 */
	virtual ~IFilterBase() = default;

	/**
	 * .
	 * 
	 */
	virtual void loadCache() = 0;
	
	/**
	 * .
	 * 
	 */
	virtual void cache() = 0;

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
};