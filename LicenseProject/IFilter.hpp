#pragma once

#include <string>

class IFilter {
public:
	IFilter() = default;
	virtual ~IFilter() = default;

	virtual void setup(const std::string& workingDirectoryPath) = 0;
	virtual void execute() const = 0;
	virtual void saveProgress(const std::string& checkpointPath) const = 0;
	virtual bool existsCheckpoint() const = 0;
	virtual void loadCheckpoint(const std::string& checkpointPath) = 0;
protected:
	std::string workingDirectoryPath;
};