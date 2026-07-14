#include <iostream>
#include <type_traits>

template <typename T>
void print_type_info() {
    if constexpr (std::is_integral_v<T>) { // C++17 的 _v 后缀，直接获取编译期值
        std::cout << "this is a int type \n";
    } else if constexpr (std::is_pointer_v<T>) {
        std::cout << "this is a pointer type \n";
    } else {
        std::cout << "other types \n";
    }
}


// 直接在参数里限制
void foo(std::integral auto x) { }

// 或者
template <typename T> requires std::is_integral_v<T>
void foo(T x);