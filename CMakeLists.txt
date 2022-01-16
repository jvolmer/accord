cmake_minimum_required(VERSION 3.13)
project(accord
  VERSION 1.0
  LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

add_subdirectory(src)
