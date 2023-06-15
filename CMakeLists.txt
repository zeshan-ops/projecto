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
    tests/modelTests/taskTests.cpp
    tests/modelTests/projectTests.cpp
    tests/modelTests/jsonDataInterfaceTests.cpp
    tests/modelTests/modelUtilTests.cpp
    tests/viewTests/viewDetailTests.cpp
    tests/viewTests/viewProjectTests.cpp
    tests/viewTests/viewTableTests.cpp
    tests/viewTests/viewUtilitiesTests.cpp
    tests/controllerTests/cliParserTests.cpp
    tests/controllerTests/initialiserTests.cpp
    tests/controllerTests/dataLoaderTests.cpp
    src/model/task.cpp
    src/model/task.h
    src/model/log.cpp
    src/model/log.h
    src/model/project.cpp
    src/model/project.h
    src/model/jsonDataInterface.cpp
    src/model/jsonDataInterface.h
    src/model/modelUtilities.cpp
    src/model/modelUtilities.h
    src/view/viewDetail.cpp
    src/view/viewDetail.h
    src/view/ansiMacros.h
    src/view/viewProject.cpp
    src/view/viewProject.h
    src/view/viewTable.cpp
    src/view/viewTable.h
    src/view/viewUtilities.cpp
    src/view/viewUtilities.h
    src/controller/command.h
    src/controller/cliParser.cpp
    src/controller/cliParser.h
    src/controller/initialiser.cpp
    src/controller/initialiser.h
    src/controller/dataLoader.cpp
    src/controller/dataLoader.h)

target_compile_options(unitTests PUBLIC -fno-exceptions -W -Wall -Wextra -Wpedantic -Wsign-conversion)

include(CodeCoverage.cmake)
append_coverage_compiler_flags()
setup_target_for_coverage_gcovr_xml(
    NAME projecto_coverage 
    EXECUTABLE unitTests
    EXCLUDE "${PROJECT_SOURCE_DIR}/src/model/json.hpp"
            "${PROJECT_SOURCE_DIR}/src/model/date.h"
            "${PROJECT_SOURCE_DIR}/tests/*")