cmake_minimum_required(VERSION 3.20)

project(LogLib
  VERSION 1.0.0
  LANGUAGES CXX)

set(name log_test)
set(cpp_file
  files/main.cpp
  files/cpp/log.cpp)

include_directories(files/include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(${name} ${cpp_file})
target_include_directories(${name} PUBLIC ${CMAKE_SOURCE_DIR}/files/include/log.h)
