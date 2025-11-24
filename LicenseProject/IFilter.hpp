#pragma once

#include "IFilterBase.hpp"
#include "DataInternalRepresentation.hpp"

#include <filesystem>
#include <type_traits>

template<typename Input, typename Output>
class IFilter : public IFilterBase {
	static_assert(std::is_base_of<DataInternalRepresentation, Input>::value, "Input must derive from DataInternalRepresentation");
	static_assert(std::is_base_of<DataInternalRepresentation, Output>::value, "Output must derive from DataInternalRepresentation");
public:
	IFilter() = default;
	virtual ~IFilter() = default; 
	const std::filesystem::path& getCachePath() const { return cachePath; }

	virtual void loadCache() override = 0;
	virtual void cache() override = 0;

protected:
	std::filesystem::path cachePath{ "" };
};