#include "Workspace.hpp"
#include "DataInternalRepresentation.hpp"

#include <memory>
#include <utility>

Workspace::Workspace(const size_t numberOfElemets)
	: internalRepresentation(numberOfElemets),
	currentFilter{ nullptr }
{
}

void Workspace::setValueAtInternalRepresentation(const size_t index, std::unique_ptr<DataInternalRepresentation> representation)
{
	internalRepresentation.at(index) = std::move(representation);
}

void Workspace::executeFilter()
{
	this->start();

	this->waitForFinish();
}
