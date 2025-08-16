#pragma once

#include <cstdint>
#include <memory>

template<typename T>
class matrix {
public:
	matrix() : pixels{ nullptr } {}
	~matrix() {};

	const T at(const int i, const int j) { return pixels[i][j]; }

private:
	const int cols{ 0 };
	const int rows{ 0 };
	T* const pixels;
};