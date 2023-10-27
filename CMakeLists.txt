cmake_minimum_required(VERSION 3.21)
project(lexicalAnalysis)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(file_parsing)
add_executable(lexicalAnalysis main.cpp)
target_link_libraries(lexicalAnalysis PUBLIC parsing)
