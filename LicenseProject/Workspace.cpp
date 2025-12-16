#include "Workspace.hpp"
#include "Path.hpp"
#include "DataInternalRepresentation.hpp"

#include <memory>
#include <utility>
#include <filesystem>

Workspace::Workspace(const std::filesystem::path& directoryPath)
	: currentFilter{ nullptr },
	internalRepresentation{}
{
	for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
		if (entry.is_regular_file() && entry.path().extension() == ".dcm") {
			internalRepresentation.emplace_back(std::make_unique<Path>(entry.path()));
			// limit to 1
			break;
		}
	}
}

void Workspace::executeFilter()
{
	for (auto& repr : internalRepresentation) {
		auto& slot = repr;
		this->submit([slot = &slot, filter = this->currentFilter] {
			auto out = filter->apply(slot->get());
			*slot = std::move(out);
			}
		);
	}

	this->start();
	this->waitForFinish();
	this->resetThreadPool();
}
