#include <iostream>
#include <cstring>
#include <utility> 
// std::move 需要这个头文件

class MyArray {
public:
    int* m_data;
    size_t m_size;

    // 1. 普通构造函数
    MyArray(size_t size) : m_size(size) {
        m_data = new int[size];
        std::cout << "【构造】申请了 " << size << " 个资源的堆内存" << std::endl;
    }

    // 2. 传统的【拷贝构造函数】（深拷贝）
    MyArray(const MyArray& other) : m_size(other.m_size) {
        m_data = new int[other.m_size];                 // 重新开辟堆内存
        std::memcpy(m_data, other.m_data, m_size * sizeof(int)); // 复制字节
        std::cout << "❌【深拷贝构造】耗费巨资，重新复制了数据" << std::endl;
    }

    // 3. 现代 C++ 的【移动构造函数】（核心！）
    // 语法：类名(类名&& other) noexcept
    MyArray(MyArray&& other) noexcept 
        : m_data(other.m_data), m_size(other.m_size) { // 直接复制指针地址（金蝉脱壳）
        
        // 【关键动作】：将原对象内部的指针置空！
        // 这一步叫“斩断后路”，防止原对象在析构时把我们刚偷过来的内存给 delete 掉
        other.m_data = nullptr;
        other.m_size = 0;
        
        std::cout << " ⚡【移动构造】轻飘飘地偷走了资源指针，几乎零开销！" << std::endl;
    }

    // 4. 析构函数
    ~MyArray() {
        if (m_data != nullptr) {
            delete[] m_data;
            std::cout << "【析构】释放了堆内存" << std::endl;
        } else {
            std::cout << "【析构】空壳对象被销毁，无资源需要释放" << std::endl;
        }
    }
};

int main() {
    std::cout << "--- 场景一：触发深拷贝 ---" << std::endl;
    MyArray a1(1000000); // 假设有一百万个数据
    MyArray a2 = a1;     // 正常复制，触发深拷贝构造。a1 和 a2 各持有一百万数据。

    std::cout << "\n--- 场景二：使用 std::move 触发移动语义 ---" << std::endl;
    // std::move(a1) 强行把 a1 转成了右值引用，告诉编译器：“a1 里的数据我不要了”
    MyArray a3 = std::move(a1); 
    
    // 此时的内存状态：
    // a3.m_data 指向了原本属于 a1 的大块堆内存。
    // a1.m_data 变成了 nullptr（变成了空壳）。

    std::cout << "\n程序结束，准备析构..." << std::endl;
    return 0;
}