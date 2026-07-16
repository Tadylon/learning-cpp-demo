#include <iostream>
#include <string>
#include <type_traits>

#include "print_obj.h"

template <typename T>
T max(T a, T b) { return a > b ? a : b; }

int a = max(3, 5);       // 推导为 int
double b = max(3.0, 5.0); // 推导为 double
// 若类型不同需显式指定：max<double>(3, 5.0);

int main()
{
    cout__(a);
    cout__(b);
    
    auto result_int = max(32, 34);
    cout__(result_int);

    return 0;
}