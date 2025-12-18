#include "GlobalExceptionHandler.hpp"

#include <exception>
#include <iostream>
#include <mutex>

std::mutex GlobalExceptionHandler::mtx{};

void GlobalExceptionHandler::handle()
{
	mtx.lock();
	try {
		throw;
	}
	catch (const std::exception& e) {
		std::cout << "[EXCEPTION] : " << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "[EXCEPTION] : unknown" << std::endl;
	}
	mtx.unlock();
}
