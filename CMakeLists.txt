cmake_minimum_required(VERSION 3.30)

# set_target_properties(Main PROPERTIES CXX_MODULE_STD ON)
# set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")

project(Main CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Main
    # STL/Iterator/it_insert.h
    # STL/Iterator/input_iterator.cpp
    # STL/Iterator/output_iterator.cpp
    # STL/Iterator/common.cpp
    # STL/Iterator/forward_it.cpp
    # STL/Iterator/bidirectional_it.cpp
    # STL/Iterator/contigour_it.cpp
    # STL/Iterator/it_declare.cpp
    # STL/Iterator/it_traverse.cpp
    # STL/Iterator/it_move.cpp
    # STL/Iterator/it_insert.cpp
    # STL/String/string_view.cpp
    # STL/String/cstyle/string_kwords.cpp
    # key_words/compare/using_typedef.cpp
    # key_words/compare_using_typedef/template_way.cpp
    # key_words/compare_using_typedef/using_local.cpp
    # STL/Utility/type_traits/integral_constant.cpp
    # STL/Utility/type_traits/sequence,.cpp
    # STL/Utility/type_traits/judgment.cpp
    # STL/stream/get_serise.cpp
    # template/func_template.cpp
    # template/template_in_class.cpp
    # template/variable_name.cpp
    # template/allocator_t.cpp
    # template/t_in_t.cpp
    # STL/stream/compare/diff_getline.cpp
    # STL/stream/compare/diff_get.cpp
    # files/Stream/write.cpp
    # files/Stream/file_open_text.cpp
    # files/Stream/read_stream.cpp
    # files/iomanip/print_map.cpp
    files/stringstream/ostringstream.cpp
)

target_include_directories(Main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 3. 明确告诉 CMake：这个目标(Target)需要编译并使用 C++20 的标准库模块