#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <string_view>
#include <tuple>

#include "print_obj.h"

// 简化的内部实现
template<typename CharT>
class basic_string_view {
public:
    const CharT* data_;  // 指向连续字符序列的指针（只读）
    size_t size_;        // 序列的长度（不是容量，也不是结束符）

    auto tie() const { 
        return std::tie(data_, size_); 
    }
};

std::string_view bad() {
    static std::string local = "temporary";
    return local; // 编译通过，但返回的是悬垂指针！local 被销毁，sv 指向无效内存。
}

int main()
{
    auto temp = bad();
    PrintContainer(temp);
    std::string_view sv = "Hello, World!";
    std::cout << "the value of sv is : " << sv << std::endl;
    sv.remove_prefix(7);   // sv 变为 "World!"
    std::cout << "the value of sv is : " << sv << std::endl;
    sv.remove_suffix(1);   // sv 变为 "World"
    std::cout << "the value of sv is : " << sv << std::endl;

    std::cout << "--------------------\n";
    basic_string_view<char> obj;
    obj.data_ = "ni hao";
    obj.size_ = 12;
    // PrintContainer(obj);
    print_all(obj);

    return 0;
}




