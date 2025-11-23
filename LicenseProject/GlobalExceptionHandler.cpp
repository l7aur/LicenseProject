#include "GlobalExceptionHandler.hpp"

#include <exception>
#include <iostream>

void GlobalExceptionHandler::handle()
{
	try {
		throw;
	}
	catch (const std::exception& e) {
		std::cout << "[EXCEPTION] : " << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "[EXCEPTION] : unknown" << std::endl;
	}
}
