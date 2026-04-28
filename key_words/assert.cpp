#include <iostream>
#include <cassert> // 必须包含头文件

void divide(int a, int b) {
    // 确保除数不为 0
    assert(b != 0); 
    std::cout << "结果是: " << a / b << std::endl;
}

// 语法：static_assert(常量表达式, "错误提示信息");

template <typename T>
void check_size() {
    // 确保处理的数据类型至少是 4 个字节
    static_assert(sizeof(T) >= 4, "该类型太小，无法处理！");
}

int main() {
    check_size<int>();   // 编译通过 (通常为 4 字节)
    // check_size<char>(); // 编译失败！报错：该类型太小，无法处理！


    divide(10, 2); // 正常运行
    divide(10, 0); // 触发断言，程序崩溃并提示错误位置
    return 0;
}