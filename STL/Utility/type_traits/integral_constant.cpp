#include <type_traits>

#include "print_obj.h"
#include "standard_time.h"

// 标准库的内部实现简化
template<typename T, T v>
struct integral_constant_imtate {
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant_imtate<T, v>;
    constexpr operator value_type() const noexcept { return value; }
};

// 函数声明
void func(int a[], int b) {

}


int main()
{
    // 两个最常用的别名：
    using true_type = integral_constant_imtate<bool, true>;
    using false_type = integral_constant_imtate<bool, false>;
    
    // 你今后会高频使用的快捷方式（C++17）：
    // 等价于 std::is_integral<int>::value
    auto result_value = std::is_integral_v<int>;   
    cout__(result_value);

    cout__("----------------------------------/n");
    
    auto result_value_ = std::is_integral<int>::value;
    cout__(result_value_);
    auto result_value_type = std::is_integral<int>::value_type();
    cout__(result_value_type);
    
    cout__("----------------------------------/n");
    //这个是什么不知道
    std::decay_t<decltype(func)>; 
    // 结果类型为 void (*)(int*, int)  (函数退化为函数指针)
    return 0;
}