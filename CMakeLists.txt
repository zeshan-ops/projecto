cmake_minimum_required(VERSION 3.26)

project(Projecto
        VERSION 0.1.0
        DESCRIPTION "CLI Project Management Tool"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(unitTests
    tests/mainTests.cpp
    tests/modelTests/logTests.cpp
    tests/modelTests/projectTests.cpp
    tests/modelTests/taskTests.cpp
    tests/modelTests/jsonDataInterfaceTests.cpp
    tests/viewTests/viewTableTests.cpp
    tests/viewTests/viewUtilitiesTests.cpp
    tests/viewTests/viewDetailTests.cpp
    tests/viewTests/viewProjectTests.cpp
    src/model/task.cpp
    src/model/task.h
    src/model/log.cpp
    src/model/log.h
    src/model/project.cpp
    src/model/project.h
    src/model/jsonDataInterface.cpp
    src/model/jsonDataInterface.h
    src/view/viewDetail.cpp
    src/view/viewDetail.h
    src/view/ansiMacros.h
    src/view/viewProject.cpp
    src/view/viewProject.h
    src/view/viewTable.cpp
    src/view/viewTable.h
    src/view/viewUtilities.cpp
    src/view/viewUtilities.h)

target_compile_options(unitTests PUBLIC -W -Wall -Wextra -Wpedantic -Wsign-conversion)

include(CodeCoverage.cmake)
append_coverage_compiler_flags()
setup_target_for_coverage_gcovr_xml(
    NAME projecto_coverage 
    EXECUTABLE unitTests
    EXCLUDE "${PROJECT_SOURCE_DIR}/src/model/json.hpp" "${PROJECT_SOURCE_DIR}/tests/*")