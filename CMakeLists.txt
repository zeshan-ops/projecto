cmake_minimum_required(VERSION 3.26)

project(Projecto
        VERSION 0.1.0
        DESCRIPTION "CLI Project Management Tool"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


if("${CMAKE_BUILD_TYPE}" STREQUAL "Coverage")
    add_subdirectory(tests)
    include(CodeCoverage.cmake)
    append_coverage_compiler_flags()
    setup_target_for_coverage_gcovr_xml(
    NAME projecto_coverage 
    EXECUTABLE unitTests
    EXCLUDE "${PROJECT_SOURCE_DIR}/src/model/json.hpp"
            "${PROJECT_SOURCE_DIR}/src/model/date.h"
            "${PROJECT_SOURCE_DIR}/tests/*")
endif()

if("${CMAKE_BUILD_TYPE}" STREQUAL "Tests")
    add_subdirectory(tests)
endif()

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    add_subdirectory(src)
    add_subdirectory(tests)
endif()

if("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    add_subdirectory(src)
    target_compile_options(projecto PUBLIC -O2)
endif()

