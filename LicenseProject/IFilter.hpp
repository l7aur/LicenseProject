#pragma once

#include "IFilterBase.hpp"
#include "DataInternalRepresentation.hpp"

#include <filesystem>
#include <type_traits>
#include <typeinfo>
#include <memory>
#include <stdexcept>

/**
 * .
 */
template<typename Input, typename Output>
class IFilter : public IFilterBase {
	static_assert(std::is_base_of<DataInternalRepresentation, Input>::value, "Input must derive from DataInternalRepresentation");
	static_assert(std::is_base_of<DataInternalRepresentation, Output>::value, "Output must derive from DataInternalRepresentation");

public:
	/**
	 * .
	 * 
	 */
	IFilter() = default;

	/**
	 * .
	 */
	virtual ~IFilter() = default; 

	/**
	 * .
	 * 
	 * \return 
	 */
	const std::filesystem::path& getCachePath() const { return cachePath; }

	/**
	 * .
	 * 
	 */
	virtual void loadCache() override = 0;

	/**
	 * .
	 * 
	 */
	virtual void cache() override = 0;
	
	/**
	 * .
	 * 
	 * \return 
	 */
	const std::type_info& inputType() override { return typeid(Input); }

	/**
	 * .
	 * 
	 * \return 
	 */
	const std::type_info& outputType() override { return typeid(Output); }
	
	/**
	 * .
	 * 
	 * \param input
	 * \return 
	 */
	std::unique_ptr<DataInternalRepresentation> apply(const DataInternalRepresentation* input)  noexcept(false) override;

	/**
	 * .
	 * 
	 * \param input
	 * \return 
	 */
	virtual std::unique_ptr<DataInternalRepresentation> process(const Input* input) noexcept(false) = 0;

protected:
	std::filesystem::path cachePath{ "" };
};

template<typename Input, typename Output>
inline std::unique_ptr<DataInternalRepresentation> IFilter<Input, Output>::apply(const DataInternalRepresentation* input)  noexcept(false)
{
	auto typed = dynamic_cast<const Input*>(input);
	if (typed == nullptr)
		throw std::runtime_error("Filter received wrong input type");

	return process(typed);
}
