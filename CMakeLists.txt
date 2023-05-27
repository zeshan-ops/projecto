cmake_minimum_required(VERSION 3.26)

project(projecto)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS off)

add_executable(unitTests
    tests/mainTests.cpp
    tests/modelTests/logTests.cpp
    tests/modelTests/projectTests.cpp
    tests/modelTests/taskTests.cpp
    tests/modelTests/jsonDataInterfaceTests.cpp
    src/model/task.cpp
    src/model/task.h
    src/model/log.cpp
    src/model/log.h
    src/model/project.cpp
    src/model/project.h
    src/model/jsonDataInterface.cpp
    src/model/jsonDataInterface.h)

target_compile_options(unitTests PUBLIC -W -Wall -Wextra -Wpedantic -Wsign-conversion)

include(CodeCoverage.cmake)
append_coverage_compiler_flags()
setup_target_for_coverage_gcovr_xml(
    NAME projecto_coverage 
    EXECUTABLE unitTests
    EXCLUDE "${PROJECT_SOURCE_DIR}/src/model/json.hpp" "${PROJECT_SOURCE_DIR}/tests/*")