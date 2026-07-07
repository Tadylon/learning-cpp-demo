#include <iostream>

class Base {
public:
    virtual void print() { std::cout << "Base" << std::endl; }
};

class Derived : public Base {
public:
    void print() override { std::cout << "Derived" << std::endl; }
    void onlyDerived() { std::cout << "Only Derived" << std::endl; }
};

int main() {
    // 1. 基本类型转换
    float f = 3.14f;
    int i = static_cast<int>(f); // 截断小数，i = 3
    std::cout << "int: " << i << std::endl;

    // 2. 向上转型（安全，隐式转换也能做，但显式更好）
    Derived d;
    Base* b = static_cast<Base*>(&d); // 子类 -> 父类
    b->print(); // 输出 Derived（虚函数多态）

    // 3. 向下转型（不安全，但程序员确信类型正确时使用）
    Base* b2 = new Derived();
    Derived* d2 = static_cast<Derived*>(b2); // 父类 -> 子类
    d2->onlyDerived(); // 能调用，前提是 b2 确实指向 Derived

    // 4. void* 转具体类型（C 语言 malloc 常用）
    void* raw = malloc(100);
    int* int_ptr = static_cast<int*>(raw);
    *int_ptr = 42;
    std::cout << *int_ptr << std::endl;
    free(raw);

    return 0;
}