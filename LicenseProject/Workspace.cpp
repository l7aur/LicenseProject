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
	for (size_t i = 0; i < internalRepresentation.size(); i++) {
		this->submit([repr = &internalRepresentation.at(i), filter = this->currentFilter] {
			std::unique_ptr<DataInternalRepresentation> out = filter->apply(repr->get());
			*repr = std::move(out);
			});
	}

	this->start();
	this->waitForFinish();
}
