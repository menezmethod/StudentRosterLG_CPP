cmake_minimum_required(VERSION 3.25)
project(StudentRosterLG_CPP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(StudentRosterLG_CPP
    src/main.cpp
    src/roster.cpp
    src/student.cpp
)
