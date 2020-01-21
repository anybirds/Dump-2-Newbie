cmake_minimum_required(VERSION 3.5)

project(Custom LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Custom SHARED
  Custom_global.h
  custom.cpp
  custom.hpp
)

target_compile_definitions(Custom PRIVATE CUSTOM_LIBRARY)
