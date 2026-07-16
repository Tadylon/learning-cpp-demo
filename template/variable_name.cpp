#include <iostream>
#include <vector>

#include "print_obj.h"

template <typename T>
class Array {
private:
    T arr[5] = {};
public:
    T& operator[](int idx) { 
        return arr[idx]; 
    }

    Array() = default;
};


// 别名：简化复杂类型
template<typename T> 
using Vec = std::vector<T>;


// 变量模板：定义一组静态成员变量
template<typename T> 
constexpr T pi = T(3.1415926535);

int main()
{
    Vec<int> v;
    // cout__(v);
    float f = pi<float>; // 3.14159f
    cout__(f);
    
    return 0;
}


