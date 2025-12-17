#pragma once

#include "FilterBase.hpp"
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
class Filter : public FilterBase {
	static_assert(std::is_base_of<DataInternalRepresentation, Input>::value, "Input must derive from DataInternalRepresentation");
	static_assert(std::is_base_of<DataInternalRepresentation, Output>::value, "Output must derive from DataInternalRepresentation");

public:
	/**
	 * Alias to allow methods to use `Input` as a generic type.
	 */
	using input_type = Input;
	
	/**
	 * Alias to allow methods to use `Output` as a generic type.
	 */
	using output_type = Output;

	/**
	 * .
	 * 
	 */
	Filter(const std::filesystem::path& _cachePath) : FilterBase{ _cachePath } {}

	/**
	 * .
	 */
	virtual ~Filter() = default; 

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
	std::unique_ptr<DataInternalRepresentation> apply(DataInternalRepresentation* input)  noexcept(false) override;

	/**
	 * .
	 * 
	 * \param input
	 * \return 
	 */
	virtual std::unique_ptr<DataInternalRepresentation> process(Input* input) noexcept(false) = 0;
};

template<typename Input, typename Output>
inline std::unique_ptr<DataInternalRepresentation> Filter<Input, Output>::apply(DataInternalRepresentation* input)  noexcept(false)
{
	auto typed = dynamic_cast<Input*>(input); // todo make the pipeline remember the output and check when adding so that this can become a `static_cast`
	if (typed == nullptr)
		throw std::runtime_error("Filter received wrong input type");

	return process(typed);
}
