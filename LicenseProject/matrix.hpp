#pragma once

#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmimgle/dcmimage.h>
#include <dcmtk/dcmdata/dcfilefo.h>
#include <dcmtk/dcmdata/dctk.h>

#include <filesystem>
#include <memory>

template<typename T>
class matrix {
public:
	matrix() = default;
	~matrix() { delete pixels; }

	const T at(const int i, const int j) { return pixels[i][j]; }
private:
	int cols{ 0 };
	int rows{ 0 };
	T* pixels{ nullptr };
};
