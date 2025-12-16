#pragma once

#include "DataInternalRepresentation.hpp"

#include <filesystem>

/**
 * .
 */
class Path : public DataInternalRepresentation 
{
public:
	Path(const std::filesystem::path& p) : path_{ p } {}
	~Path() = default;

	[[nodiscard]] const std::filesystem::path& getPath() const { return path_; }
private:
	const std::filesystem::path path_;
};