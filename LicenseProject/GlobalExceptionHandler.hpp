#pragma once

#include <mutex>

/**
 * .
 */
class GlobalExceptionHandler {
public:
	/**
	 * .
	 * 
	 */
	static void handle();

private:
	/**
	 * .
	 */
	static std::mutex mtx;
};