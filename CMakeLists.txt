cmake_minimum_required(VERSION 3.20)

project(LogLib
  VERSION 1.0.0
  LANGUAGES CXX)

set(name gmlog)
set(cpp_file
  files/main.cpp
  files/cpp/log.cpp)

include_directories(files/include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(${name} ${cpp_file})
target_include_directories(${name} PUBLIC ${CMAKE_SOURCE_DIR}/files/include/log.h)

if(CMAKE_BUILD_TYPE MATCHES Release)
  target_compile_options(${name} INTERFACE -03 -DNDEBUG)
endif()

include(CPack)
