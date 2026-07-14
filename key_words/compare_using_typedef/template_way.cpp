#include <iostream>
#include <vector>
#include <type_traits>
#include <memory>

#include "print_obj.h"

// 1. 定义分配器模板，必须有一个模板参数 T（代表要分配的元素类型）
template<typename T>
class MyAlloc {
public:
    // 2. 类型别名（标准要求必须有的嵌套类型）
    using value_type = T;

    // 3. 构造函数（标准要求拷贝构造和默认构造是平凡的，且能跨类型转换）
    MyAlloc() = default;
    template<typename U>
    MyAlloc(const MyAlloc<U>&) {} // 用于 vector 内部 rebind（将 int 分配器转为 char 分配器）

    // 4. 核心分配函数：allocate
    // 参数 n：需要分配 n 个 T 类型的元素（注意：不是字节数！）
    // 返回值：指向未初始化内存块的指针（必须是 alignas(T) 对齐的）
    T* allocate(std::size_t n) {
        std::cout << "Custom allocator: allocated  " << n << " elements , " << n * sizeof(T) << " bytes . " << std::endl;
        // 这里调用全局 ::operator new 返回原始内存（或者你自己用 malloc）
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    // 5. 核心释放函数：deallocate
    void deallocate(T* ptr, std::size_t n) noexcept {
        std::cout << "Custom allocator: allocated  " << n << " elements of memory , " << std::endl;
        ::operator delete(ptr); // 或者 free(ptr)
    }

    // 6. 重载 == 和 !=（C++20 之前要求比较）
    template<typename U>
    bool operator==(const MyAlloc<U>&) const { return true; } // 一般来说，同一个分配器默认相等（表示可以互相释放）
    template<typename U>
    bool operator!=(const MyAlloc<U>&) const { return false; }
};


#if 0
// 靠 typedef 无法直接做到，必须写一个模板结构体，把类型藏在 ::type 里
template<typename T>
struct MyVector {
    typedef std::vector<T, MyAlloc<T>> type; // 恶心，访问时必须加 ::type
};

// 使用时极其丑陋：
MyVector<int>::type v1; 

#else
// 这就是标准的“别名模板（Alias Template）”
template<typename T>
using MyVector = std::vector<T, MyAlloc<T>>;

// 使用时就像普通类型一样自然：
MyVector<int> v1; // 完美！


#endif


int main()
{

    v1.push_back(10);
    v1.push_back(101);
    PrintContainer(v1);

    return 0;
}
