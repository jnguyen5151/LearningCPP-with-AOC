
cmake_minimum_required(VERSION 3.16)

project(LearnCPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories({CMAKE_SOURCE_DIR}/include)

add_library(aoc_lib 
	lib/aoc.cpp
	lib/utility_functions.cpp	
)

target_include_directories(aoc_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(LearnCPP src/LearnCPP.cpp)

target_link_libraries(LearnCPP PRIVATE aoc_lib)

file(COPY ${CMAKE_SOURCE_DIR}/src/input.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/src/input2.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/src/input3.txt DESTINATION ${CMAKE_BINARY_DIR})