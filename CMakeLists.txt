cmake_minimum_required(VERSION 3.16)

project(PhotoManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PhotoManager
    src/main.cpp
    src/Photo.cpp
)

target_include_directories(PhotoManager PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)