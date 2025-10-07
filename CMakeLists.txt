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
    "img2obj/"
)

# Add headers
set(HEADERS
    "img2obj/"
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    debug       "${PROJECT_SOURCE_DIR}/lib/Debug/dcmtk.lib"
    
    optimized   "${PROJECT_SOURCE_DIR}/lib/Release/dcmtk.lib"
)

# Add project cmake header
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Identification.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/Identification.h"
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
set(DLLS dcmtk.dll )
foreach(dll ${DLLS})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<IF:$<CONFIG:Debug>,${PROJECT_SOURCE_DIR}/dll/Debug/${dll},${PROJECT_SOURCE_DIR}/dll/Release/${dll}>"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
    )
endforeach()