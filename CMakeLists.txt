cmake_minimum_required(VERSION 3.4)

project(main)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable( main
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp
        )
