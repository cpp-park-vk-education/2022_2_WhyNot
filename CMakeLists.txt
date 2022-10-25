cmake_minimum_required(VERSION 3.0)
project(2022_2_WHYNOT CXX)

option(BUILD_FOR_TEST "Build for test" OFF)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp)

if (BUILD_FOR_TEST)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )
endif ()

enable_testing()

add_subdirectory(Tests)