#include "Workspace.hpp"
#include "DataInternalRepresentation.hpp"

#include <memory>
#include <utility>

Workspace::Workspace(const size_t numberOfElemets)
	: internalRepresentation(numberOfElemets),
	currentFilter{ nullptr }
{
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
}
