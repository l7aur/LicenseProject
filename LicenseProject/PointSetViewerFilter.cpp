#include "PointSetViewerFilter.hpp"
#include "Filter.hpp"
#include "DataInternalRepresentation.hpp"

#include <filesystem>
#include <memory>
#include <fstream>
#include <stdexcept>
#include <string>

PointSetViewerFilter::PointSetViewerFilter(const std::filesystem::path& _cachePath)
	: Filter{ _cachePath },
	mtx{}
{
}

void PointSetViewerFilter::loadCache()
{
}

void PointSetViewerFilter::cache()
{
}

std::unique_ptr<DataInternalRepresentation> PointSetViewerFilter::process(input_type* input) noexcept(false)
{
	static unsigned int setNumber = 0;
	std::string fileName{ std::to_string(setNumber++).append(".txt") };
	std::filesystem::path filePath = cachePath / fileName;

	mtx.lock();
	std::ofstream outStream{ filePath, std::ios::out};
	if (!outStream)
		throw std::runtime_error("Unable to open file: " + fileName);

	outStream << input->toString2D();

	if(!outStream.good())
		throw std::runtime_error("Unable to write to file: " + fileName);

	outStream.close();
	mtx.unlock();
	return std::make_unique<output_type>(*input);
}
