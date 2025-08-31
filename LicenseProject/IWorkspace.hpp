#pragma once

namespace std::filesystem { class path; };

class IWorkspace {
public:
	virtual void serialize(const std::filesystem::path&) const = 0;
};