cmake_minimum_required(VERSION 3.0)
project(TEST CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (BUILD_FOR_TEST)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -O0")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

endif ()

include_directories("..include/")

set(SRCS
        src/MathExpression.cpp
        src/MathCalculator.cpp
        src/MathChecker.cpp
        src/MathParser.cpp
        src/MathConverter.cpp
        src/Graph.cpp)

file(GLOB SOURCES
        test.cpp
        ${SRCS})

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} GTest::gtest_main)
