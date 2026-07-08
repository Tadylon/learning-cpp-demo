#include <iostream>

class Base {
public:
    int a = 1;
    // double alignment = 10.0;
};

class Derived : public Base {
public:
    int b = 2; // 子类比父类多了 4 字节
};

int main() {
    Base base_obj;               // 实际只占 4 字节（假设 int 4字节）
    Derived* derived_ptr = static_cast<Derived*>(&base_obj); // 强行转换
    
    // 此时 derived_ptr 认为内存有 8 字节，写 b 时越界
    derived_ptr->b = 999;        // 未定义行为！大概率 Crash 或覆写栈数据
    
    std::cout << base_obj.a << std::endl; // 可能根本运行不到这里
    return 0;
}