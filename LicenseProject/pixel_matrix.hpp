#pragma once

#include <cstdint>
#include <memory>

template<typename T>
class pixel_matrix {
public:
	pixel_matrix() {};
	~pixel_matrix() {};

	const T at(const int i, const int j) { return pixels[i][j]; }

private:
	const int cols{ 0 };
	const int rows{ 0 };
	std::unique_ptr<T> pixels;
};