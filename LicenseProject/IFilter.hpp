#pragma once

class IFilter {
public:
	IFilter() = default;
	virtual ~IFilter() = default;

	virtual void execute() const = 0;
	virtual void saveProgress() const = 0;
	virtual bool existsCheckpoint() const = 0;
	virtual void loadCheckpoint() = 0;

};