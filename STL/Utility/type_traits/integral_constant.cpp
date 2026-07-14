#include <type_traits>

#include "print_obj.h"

// 标准库的内部实现简化
template<typename T, T v>
struct integral_constant {
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant<T, v>;
    constexpr operator value_type() const noexcept { return value; }
};




int main()
{

    // 两个最常用的别名：
    using true_type = integral_constant<bool, true>;
    using false_type = integral_constant<bool, false>;
    
    // 你今后会高频使用的快捷方式（C++17）：
    std::is_integral_v<int>;   // 等价于 std::is_integral<int>::value
    
    
    
}