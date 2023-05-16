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
    tests/modelTests/jsonDataTests.cpp)

add_library(model STATIC
    src/model/task.cpp
    src/model/task.h
    src/model/log.cpp
    src/model/log.h
    src/model/project.cpp
    src/model/project.h
    src/model/jsonData.cpp
    src/model/jsonData.h)

target_link_libraries(unitTests model)