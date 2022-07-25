cmake_minimum_required(VERSION 3.0.0)
project(2-task VERSION 0.1.0)

set(SOURCES main.cpp)

add_executable(2-task ${SOURCES})

target_include_directories(2-task PUBLIC ${MY_INCLUDE_DIR})