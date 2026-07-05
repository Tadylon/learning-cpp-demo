
#include <iostream>
#include <string>


class Wrapper {
public:
    int& getRef() { return m_data; }            // 返回可修改的引用
    const int& getConstRef() const { return m_data; } // 返回只读引用
private:
    int m_data = 0;
};

class MyClass {
private:
    int m_val;
public:
    MyClass(){

    }
    // 读函数：末尾加 const，保证只读，可以被 const 对象调用
    int getVal() const {
        // m_val = 10; // ❌ 错误：const 成员函数不能修改成员变量
        return m_val; // ✅ 正确
    }

    // 写函数：不加 const，允许修改
    void setVal(int v) {
        m_val = v; // ✅ 正确
    }
};

int main(){
    const MyClass obj1; 
    obj1.getVal(); // ✅ const 对象只能调用 const 成员函数
    // obj1.setVal(5); // ❌ 错误：const 对象不能调用非 const 成员函数
    
    Wrapper w;
    w.getRef() = 10;    // ✅ 可以修改
    // w.getConstRef() = 20; // ❌ 错误：返回值是 const 引用，不能赋值
    return 0;
}