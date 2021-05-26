cmake_minimum_required(VERSION 3.8)

project(CXXPrimer)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

file(GLOB_RECURSE SRCS src/*.cpp)

add_executable(${PROJECT_NAME} ${SRCS})