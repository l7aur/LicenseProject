#include "Types.hpp"
#include "Slice.hpp"
#include "PointSet.hpp"
#include "PixelExtractorFilter.hpp"
#include "GlobalExceptionHandler.hpp"

#include <memory>
#include <vector>
#include <utility>
#include <filesystem>
#include <string_view>

PixelExtractorFilter::PixelExtractorFilter(const std::string_view& cachePath_)
{
	cachePath = cachePath_;
}

void PixelExtractorFilter::execute(const std::vector<std::filesystem::path>& paths, std::vector<workspace>& wspaces)
{
	try {
		for (size_t i = 0; i < wspaces.size(); ++i)
			submit(
				[&wspaces, i, &paths]() {
					Slice s{ paths.at(i) };
					wspaces[i] = std::make_unique<types>(std::move(s));
				}
			);
	}
	catch (...) {
		GlobalExceptionHandler::handle();
	}
}