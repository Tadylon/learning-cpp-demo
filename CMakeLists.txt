cmake_minimum_required(VERSION 3.30)

# set_target_properties(Main PROPERTIES CXX_MODULE_STD ON)
# set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")

project(Main CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Main
    # STL/Container/map/base_map.cpp
    # STL/Container/map/init_map.cpp
    # function_oop/lambda/auto_lambda.cpp
    # STL/var_type/auto_type.cpp
    # STL/Utility/tuple_pair/tuple_test.cpp
    # STL/Utility/tuple_pair/pair_test.cpp
    STL/Container/container/define.cpp
)

target_include_directories(Main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

