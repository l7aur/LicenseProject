#pragma once

#include <typeinfo>

class IFilterBase {
public:
	virtual ~IFilterBase() = default;

	virtual void loadCache() = 0;
	virtual void cache() = 0;

	virtual const std::type_info& inputType() = 0;
	virtual const std::type_info& outputType() = 0;

protected:
	IFilterBase() = default;
};