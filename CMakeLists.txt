cmake_minimum_required(VERSION 3.20)

project(Main CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Main
    async/thread/atomic_deal.cpp
    async/chrono/standard_time.h
    )

# target_include_directories(Main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
