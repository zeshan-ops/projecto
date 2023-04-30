cmake_minimum_required(VERSION 3.26)

project(projecto)

add_executable(test_model
    tests/taskTest.cpp
    tests/projectTest.cpp
    tests/noteTest.cpp
    tests/dataReadingTest.cpp)

add_executable(test_view
    src/view/main.cpp)

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

add_library(view STATIC
    src/view/ansiMacros.h
    src/view/projectView.cpp
    src/view/projectView.h)

target_compile_features(test_model PRIVATE cxx_std_11)
target_compile_features(model PRIVATE cxx_std_11)
target_compile_features(view PRIVATE cxx_std_11)
target_compile_features(test_view PRIVATE cxx_std_11)

target_link_libraries(test_model model)
target_link_libraries(test_view model view)