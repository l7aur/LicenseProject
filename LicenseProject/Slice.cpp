#include "Slice.hpp"

#include <dcmtk/dcmdata/dcfilefo.h>
#include <dcmtk/dcmdata/dctk.h>

namespace {
	const std::pair<float, float> fetchPixelSpacing(const std::string& path) {
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

Slice::Slice(const std::filesystem::path& p)
	: file{ p }
{
	img = std::make_unique<DicomImage>(p.string().c_str());
	pixelSpacing = fetchPixelSpacing(p.string());
}
