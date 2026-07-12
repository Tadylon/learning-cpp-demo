cmake_minimum_required(VERSION 3.20)

project(Main CXX)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Main
    async/async_pro/template_async_future.cpp
    )
