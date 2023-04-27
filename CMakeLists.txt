cmake_minimum_required(VERSION 3.26)

project(projecto)

add_executable(tests
    tests/taskTest.cpp
    tests/projectTest.cpp
    tests/noteTest.cpp
    tests/dataReadingTest.cpp)

add_library(model STATIC
    src/model/task.cpp
    src/model/task.h
    src/model/note.cpp
    src/model/note.h
    src/model/project.cpp
    src/model/project.h
    src/model/txtDataUtility.cpp
    src/model/txtDataUtility.h
    src/model/json.hpp)

target_compile_features(tests PRIVATE cxx_std_11)
target_compile_features(model PRIVATE cxx_std_11)

target_link_libraries(tests model)