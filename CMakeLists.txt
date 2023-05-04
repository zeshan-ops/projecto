cmake_minimum_required(VERSION 3.26)

project(projecto)

add_executable(unitTests
    tests/taskTest.cpp
    tests/projectTest.cpp
    tests/noteTest.cpp
    tests/dataReadingTest.cpp
    tests/viewUtilTest.cpp)

add_executable(test_view
    src/view/main.cpp)

add_library(model STATIC
    src/model/task.cpp
    src/model/task.h
    src/model/note.cpp
    src/model/note.h
    src/model/project.cpp
    src/model/project.h
    src/model/jsonDataUtility.cpp
    src/model/jsonDataUtility.h
    src/model/json.hpp)

add_library(view STATIC
    src/view/ansiMacros.h
    src/view/projectView.cpp
    src/view/projectView.h
    src/view/viewUtilities.cpp
    src/view/viewUtilities.h)

target_compile_features(unitTests PRIVATE cxx_std_11)
target_compile_features(model PRIVATE cxx_std_11)
target_compile_features(view PRIVATE cxx_std_11)
target_compile_features(test_view PRIVATE cxx_std_11)

target_link_libraries(unitTests model view)
target_link_libraries(test_view model view)