#pragma once

#include <string>

class IFilter {
public:
	IFilter() = default;
	virtual ~IFilter() = default;

	virtual void setup(const std::string&) = 0;
	virtual void setup() = 0;
	virtual void execute() const = 0;
	virtual void saveProgress(const std::string&) const = 0;
	virtual bool existsCheckpoint() const = 0;
	virtual void loadCheckpoint(const std::string&) = 0;
protected:
	std::string workingDirectoryPath;
};