cmake_minimum_required(VERSION 3.10)
project(CppFErunner VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(${PROJECT_NAME} main.cpp)
