cmake_minimum_required(VERSION 3.20)

# set_target_properties(Main PROPERTIES CXX_MODULE_STD ON)
# set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")

project(Main CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LearningCppDemo
    key_words/constexpr.cpp
)

add_executable(cilent 
    # web/socket/cilent.cpp
    web/socket/clinet_pro.cpp
)

add_executable(server
    # web/socket/serve.cpp
    web/socket/server2.cpp
)

add_library(yazi_socket STATIC
    include/socket/socket.cpp   # <--- 指向你的 socket.cpp 路径
)

target_include_directories(LearningCppDemo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(cilent PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(server PRIVATE yazi_socket)
