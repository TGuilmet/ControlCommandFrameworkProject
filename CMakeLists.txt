cmake_minimum_required(VERSION 3.15)
project(ControlFramework C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SRC
    src/*.c
    tests/*.c
)

add_executable(app ${SRC})

option(RUN_TESTS "Enable tests" OFF)

if(RUN_TESTS)
    add_compile_definitions(RUN_TESTS)
endif()
