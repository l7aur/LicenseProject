cmake_minimum_required(VERSION 3.30)

# Project name
project(
    img2obj
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add sources
set(SOURCES
    "img2obj/Core/ExecutionPipeline.cpp"
    "img2obj/DAO/PointSet.cpp"
    "img2obj/DAO/Slice.cpp"
    "img2obj/Filters/CannyEdge/CannyEdgeFilter.cpp"
    "img2obj/Filters/PixelExtractor/PixelExtractorFilter.cpp"
    "img2obj/Filters/PointExtractor/PointExtractorFilter.cpp"
    "img2obj/Main/main.cpp"
)

# Add headers
set(HEADERS
    "img2obj/Core/ExecutionPipeline.hpp"
    "img2obj/DAO/PointSet.hpp"
    "img2obj/DAO/Slice.hpp"
    "img2obj/DAO/IWorkspace.hpp"
    "img2obj/DataStructures/thread_pool.hpp"
    "img2obj/DataStructures/thread_safe_queue.hpp"
    "img2obj/Filters/CannyEdge/CannyEdgeFilter.hpp"
    "img2obj/Filters/IFilter.hpp"
    "img2obj/Filters/PixelExtractor/PixelExtractorFilter.hpp"
    "img2obj/Filters/PointExtractor/PointExtractorFilter.hpp"
    "img2obj/Misc/Settings.hpp"
    "img2obj/Misc/Types.hpp"
    "img2obj/Misc/Warnings.hpp"
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    debug       "${PROJECT_SOURCE_DIR}/lib/Debug/dcmtk.lib"
    debug       "${PROJECT_SOURCE_DIR}/lib/Debug/glfw3dll.lib"
    debug       "${PROJECT_SOURCE_DIR}/lib/Debug/libglew32d.lib"
    debug       "${PROJECT_SOURCE_DIR}/lib/Debug/opencv_world4120d.lib"
    
    optimized   "${PROJECT_SOURCE_DIR}/lib/Release/dcmtk.lib"
    optimized   "${PROJECT_SOURCE_DIR}/lib/Release/glfw3dll.lib"
    optimized   "${PROJECT_SOURCE_DIR}/lib/Release/libglew32.lib"
    optimized   "${PROJECT_SOURCE_DIR}/lib/Release/opencv_world4120.lib"
)

# Add project cmake header
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/img2obj/Misc/Version.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/Version.h"
    @ONLY
)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")

# MSVC-dependent configuration
if(MSVC)
    # Change debug working directory
    set_target_properties(${PROJECT_NAME} PROPERTIES
    	VS_DebugGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
    )

    # Set compilation flag for CXX 20	    
    target_compile_options(${PROJECT_NAME} PRIVATE /Zc:__cplusplus)
endif()

# Expose build configuration
target_compile_definitions(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:DEBUG_BUILD>
    $<$<CONFIG:Release>:RELEASE_BUILD>
)

# Copy DLLs after build
set(DLLS_DEBUG dcmtk.dll glew32d.dll glfw3.dll opencv_videoio_ffmpeg4120_64.dll opencv_world4120d.dll)
set(DLLS_RELEASE dcmtk.dll glew32.dll glfw3.dll opencv_videoio_ffmpeg4120_64.dll opencv_world4120.dll)

foreach(dll "$<IF:$<CONFIG:Debug>,${DLLS_DEBUG},${DLLS_RELEASE}>")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<IF:$<CONFIG:Debug>,${PROJECT_SOURCE_DIR}/dll/Debug/${dll},${PROJECT_SOURCE_DIR}/dll/Release/${dll}>"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
    )
endforeach()