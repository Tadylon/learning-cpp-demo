cmake_minimum_required(VERSION 3.30)

# set_target_properties(Main PROPERTIES CXX_MODULE_STD ON)
# set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")

project(Main CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Main
    # value.cpp
    STL/Utility/move_synax/l_rvalue.cpp
)

# target_include_directories(Main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 3. 明确告诉 CMake：这个目标(Target)需要编译并使用 C++23 的标准库模块