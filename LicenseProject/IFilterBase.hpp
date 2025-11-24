#pragma once

class IFilterBase {
public:
	virtual ~IFilterBase() = default;

	virtual void loadCache() = 0;
	virtual void cache() = 0;

protected:
	IFilterBase() = default;
};