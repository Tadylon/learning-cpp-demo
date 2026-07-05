#include <iostream>
// #include <vector>

int main() {
    // 检查是否定义了 MSVC STL 的特有宏
#ifdef _MSVC_STL_VERSION
    std::cout << "Standard Library: MSVC STL version " << _MSVC_STL_VERSION << std::endl;
#endif

    // 检查是否定义了 LLVM libc++ 的特有宏
#ifdef _LIBCPP_VERSION
    std::cout << "Standard Library: LLVM libc++ version " << _LIBCPP_VERSION << std::endl;
#endif

    return 0;
}