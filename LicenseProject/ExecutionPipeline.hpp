#pragma once

#include "Settings.hpp"
#include "IFilter.hpp"
#include "Slice.hpp"

#include <list>
#include <string>
#include <memory>
#include <vector>
#include <filesystem>

class ExecutionPipeline
{
public:
	ExecutionPipeline(const std::filesystem::path dir);
	~ExecutionPipeline() = default;
	ExecutionPipeline(ExecutionPipeline&) = delete;
	void operator=(const ExecutionPipeline&) = delete;

	void addFilter(std::unique_ptr<IFilter> newFilter);
	void executeWithCheckpoints();
	void executeWithoutCheckpoints();

private:
	std::vector<std::pair<std::filesystem::path, std::unique_ptr<Slice>>> workspace;
	std::list<std::unique_ptr<IFilter>> filters{};
	const std::filesystem::path directory{ "" };
};

