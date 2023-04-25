cmake_minimum_required(VERSION 3.26)

project(projecto)

add_executable(tests
    tests/taskTest.cpp)

add_library(model STATIC
    src/model/task.cpp
    src/model/task.h)

target_compile_features(tests PRIVATE cxx_std_14)

target_link_libraries(tests model)