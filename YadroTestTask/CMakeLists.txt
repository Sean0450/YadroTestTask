cmake_minimum_required(VERSION 3.15)

project(YadroTestTask LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")

include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCES})
