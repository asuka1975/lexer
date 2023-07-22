cmake_minimum_required(VERSION 3.22)

project(lexer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES src/ *.cpp)
list(FILTER SOURCES EXCLUDE REGEX ".*cmake-build.*$")

add_library(lexer STATIC ${SOURCES})
target_include_directories(lexer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(lexer_runner main.cpp)
target_include_directories(lexer_runner PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(lexer_runner PRIVATE lexer)