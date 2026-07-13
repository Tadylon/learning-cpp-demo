cmake_minimum_required(VERSION 3.30)

# set_target_properties(Main PROPERTIES CXX_MODULE_STD ON)
# set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")

project(Main CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Main
    # STL/Utility/move_synax/l_rvalue.cpp
    # STL/Utility/move_synax/template_move_synatx.cpp
    # STL/Utility/move_synax/ptr_reference.cpp
    # STL/Iterator/input_iterator.cpp
    # STL/Iterator/output_iterator.cpp
    # STL/Iterator/common.cpp
    # STL/Iterator/forward_it.cpp
    # STL/Iterator/bidirectional_it.cpp
    # STL/Iterator/contigour_it.cpp
    # STL/Iterator/it_declare.cpp
    # STL/Iterator/it_traverse.cpp
    # STL/Iterator/it_move.cpp
    STL/Iterator/it_insert.cpp
)

# target_include_directories(Main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 3. 明确告诉 CMake：这个目标(Target)需要编译并使用 C++23 的标准库模块