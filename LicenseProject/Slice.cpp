#include "Slice.hpp"

#include <dcmtk/dcmdata/dcfilefo.h>
#include <dcmtk/dcmdata/dctk.h>

#include <filesystem>
#include <fstream>

namespace {
	inline const std::string getFileNameFromPath(const std::string& path) {
		size_t index = path.find_last_of('\\');
		return path.substr(index + 1);
	}

	inline const std::pair<float, float> fetchPixelSpacing(const std::string& path) {
		DcmFileFormat ff{};
		ff.loadFile(path.c_str());
		
		DcmDataset* dataset = ff.getDataset();
		std::string spacing;
		OFCondition status = dataset->findAndGetOFString(DCM_PixelSpacing, spacing);
		if (status.bad())
			throw std::exception(status.text());

		size_t index = spacing.find_first_of('\\');
		double spacingX = std::atof(spacing.substr(0, index).c_str());
		double spacingY = std::atof(spacing.substr(index + 1).c_str());
		return { static_cast<float>(spacingX), static_cast<float>(spacingY) };
	}
}

Slice::Slice(const std::string& path) :
	fileName{ getFileNameFromPath(path) },
	img{ std::make_unique<DicomImage>(path.c_str()) },
	pixelSpacing{ fetchPixelSpacing(path) }
{ 
}

void Slice::process(const size_t i, const std::string path, std::vector<matrix<Settings::pixel>>& matrices)
{
	Slice slice{ path };
	//matrices.at(i) = slice.convertToMatrix();
}

void Slice::saveCheckpoint(const std::filesystem::path& folderPath)
{
	// need a better solution because it takes too much time
	/*const std::filesystem::path checkpointFileID = folderPath / (fileName + ".txt");
	std::ofstream out{ checkpointFileID };
	out << getNumberOfColumns() << ' ' << getNumberOfRows() << '\n'
		<< getPixelSpacingX() << ' ' << getPixelSpacingY() << '\n';
	for (size_t i = 0; i < getNumberOfColumns() * getNumberOfRows(); ++i)
		out << getPixelData()[i] << '\n';
	out.close();*/
}

matrix<Settings::pixel> Slice::convertToMatrix() const
{
	return matrix<Settings::pixel>();
}
