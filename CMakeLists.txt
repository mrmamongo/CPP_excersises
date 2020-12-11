cmake_minimum_required(VERSION 3.4)

set(
        HUNTER_CACHE_SERVERS
        "https://github.com/bmstu-iu8-cpp-sem-3/hunter-cache"
        CACHE STRING "Default cache server"
)

include("tools/gate/cmake/HunterGate.cmake")

HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.278.tar.gz"
        SHA1 "35fa55bc1dfcf9f4d7264f8bb26cd1759ce1ae07"
)

project(Ex1.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest CONFIG REQUIRED)
hunter_add_package(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED)

add_library( Ex1
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/Moon.cpp
        )

add_executable( tests
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
        )

target_include_directories( tests PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_include_directories( Ex1 PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Ex1 nlohmann_json::nlohmann_json)
target_link_libraries(tests GTest::gtest_main Ex1)

enable_testing()
add_test(
        NAME unit_test
        COMMAND tests
)
