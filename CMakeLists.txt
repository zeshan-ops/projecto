cmake_minimum_required(VERSION 3.26)

project(projecto)

add_executable(tests
    src/model/task.cpp
    tests/taskTest.cpp)

target_compile_features(tests PRIVATE cxx_std_14)