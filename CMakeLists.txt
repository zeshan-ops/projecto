cmake_minimum_required(VERSION 3.26)

project(projecto)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(model STATIC
    src/model/task.cpp
    src/model/task.h
    src/model/log.cpp
    src/model/log.h
    src/model/project.cpp
    src/model/project.h)