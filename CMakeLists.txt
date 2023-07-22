cmake_minimum_required(VERSION 3.22)

project(lexer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES src/ *.cpp)
list(FILTER SOURCES EXCLUDE REGEX ".*cmake-build.*$")
message("source files: ${SOURCES}")


add_executable(lexer main.cpp ${SOURCES})
target_include_directories(lexer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)