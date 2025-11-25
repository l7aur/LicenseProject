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
	using input_type = Input;
	using output_type = Output;

	/**
	 * .
	 * 
	 */
	IFilter(const std::filesystem::path& _cachePath) : IFilterBase{ _cachePath } {}

	/**
	 * .
	 */
	virtual ~IFilter() = default; 

	/**
	 * .
	 * 
	 */
	virtual void loadCache() noexcept(false) override = 0;

	/**
	 * .
	 * 
	 */
	virtual void cache() noexcept(false) override = 0;
	
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
	virtual std::unique_ptr<DataInternalRepresentation> process(const input_type* input) noexcept(false) = 0;
};

template<typename Input, typename Output>
inline std::unique_ptr<DataInternalRepresentation> IFilter<Input, Output>::apply(const DataInternalRepresentation* input)  noexcept(false)
{
	auto typed = dynamic_cast<const Input*>(input);
	if (typed == nullptr)
		throw std::runtime_error("Filter received wrong input type");

	return process(typed);
}
