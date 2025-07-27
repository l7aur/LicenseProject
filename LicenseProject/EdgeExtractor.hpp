#pragma once

#include "thread_pool.hpp"

class Slice;

class EdgeExtractor : protected thread_pool
{
public:
	EdgeExtractor(const bool withCheckpoints);
	~EdgeExtractor() {};

private:
};

