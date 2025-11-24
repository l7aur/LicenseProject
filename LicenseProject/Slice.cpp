#include "Slice.hpp"
#include "Pixel.hpp"
#include "Point3.hpp"

#include <dcmtk/dcmdata/dcfilefo.h>
#include <dcmtk/dcmdata/dcdatset.h>
#include <dcmtk/dcmimgle/dcmimage.h>
#include <dcmtk/dcmdata/dcdeftag.h>
#include <dcmtk/ofstd/ofcond.h>
#include <string.h>
#include <cmath>
#include <exception>
#include <filesystem>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace {
	std::pair<float, float> fetchPixelSpacing(DcmDataset* const dataset) {
		const char* temp = nullptr;
		OFCondition status = dataset->findAndGetString(DCM_PixelSpacing, temp);
		if (status.bad() || temp == nullptr)
			throw std::exception(status.text());

		std::string str = temp;
		size_t index = str.find_first_of('\\');
		double spacingX = std::atof(str.substr(0, index).c_str());
		double spacingY = std::atof(str.substr(index + 1).c_str());
		return { static_cast<float>(spacingX), static_cast<float>(spacingY) };
	}

	Point3 fetchTLHC(DcmDataset* const dataset) {
		const char* temp{ "" };
		OFCondition status = dataset->findAndGetString(DCM_ImagePositionPatient, temp);
		if (status.bad() || temp == nullptr)
			throw std::exception(status.text());

		std::string str = temp;
		size_t index = str.find_first_of('\\');
		double x = std::atof(str.substr(0, index).c_str());
		size_t index2 = str.substr(index + 1).find_first_of('\\');
		double y = std::atof(str.substr(index + 1, index2).c_str());
		double z = std::atof(str.substr(index2 + 1).c_str());
		return Point3(x, y, z);
	}

	std::string fetchUID(DcmDataset* const dataset) {
		const char* temp{ "" };
		OFCondition status = dataset->findAndGetString(DCM_SOPInstanceUID, temp);
		if (status.bad() || temp == nullptr)
			throw std::exception(status.text());
		return temp;
	}

}

Slice::Slice(const std::filesystem::path& p)
	: file{ p }
{
	DicomImage img{ p.string().c_str() };
	width = img.getWidth();
	height = img.getHeight();
	pixels = std::make_unique<std::vector<Pixel>>(static_cast<size_t>(width * height));
	std::memmove(pixels.get()->data(), img.getOutputData(8 * sizeof(Pixel)), static_cast<size_t>(width * height) * sizeof(Pixel));
	processDataset(p.string());
}

void Slice::processDataset(const std::string& path)
{
	DcmFileFormat ff{};
	ff.loadFile(path.c_str());

	DcmDataset* dataset = ff.getDataset();
	pixelSpacing = fetchPixelSpacing(dataset);
	tlhc = fetchTLHC(dataset);
	uid = fetchUID(dataset);
}