#include <iostream>
#include <vector>
#include <utility>
#include "async/chrono/standard_time.h"
#include "STL/Iterator/it_insert.h"

std::vector<int> createBigVector() {
    std::vector<int> v(1000000, 42);
    return v;  // 返回时，按旧标准会拷贝整个容器（1百万个整数）
}

int main() {
    int x = 10;
    int& lref = x;        // 正确：左值引用绑定左值
    int&& rref = 20;      // 正确：右值引用绑定临时值（字面量）
    // int&& rref2 = x;      // 错误！右值引用不能绑定左值
    {
        Timer timer("copy");
        std::vector<int> big = createBigVector(); 
        // 这里发生了两次拷贝（虽然编译器做了优化，但逻辑上仍存在风险）
    }
    std::vector<int> a = {2,54,23};
    std::cout << "the value of vectora is : ";
    PrintContainer(a);
    
    std::vector<int> b = std::move(a);
    PrintContainer(b);
    PrintContainer(a);

    return 0;
}







