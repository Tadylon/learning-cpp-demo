#include <iostream>
#include <string>
#include <array>

void func(int arr_param[10]) { 
    // 在这里，arr_param 的类型不再是 int[10]，而是 int* ！！！
    // sizeof(arr_param) = 8（指针的大小），而不是 40
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int* p = arr;
    std::array<int, 5> stdarray;
    // 1. sizeof 不同
    auto arr_size = sizeof(arr); // 20
    std::cout << "the size of arr : " << arr_size << std::endl;
    auto point_size = sizeof(p);   // 8（64位系统）
    std::cout << "the size of point_size : " << point_size << std::endl;
    auto array_size = sizeof(stdarray);   // 8（64位系统）
    std::cout << "the size of array_size : " << array_size << std::endl;
    std::cout << "the size of array : " << stdarray.size() << std::endl;
    // 2. 取地址类型不同
    // auto p = static_cast<int>(&arr);        // int(*)[5]（指向整个数组的指针）
    // auto p_postion = static_cast<int>(&p);          // int**（指向指针变量的指针）

    // 3. 指针运算步长不同
    // arr + 1;     // 跳过一个 int（4字节），指向第二个元素
    // &arr + 1;    // 跳过整个数组（20字节），指向数组末尾之后
    // p + 1;       // 跳过一个 int（4字节）

    system("pause");
    return 0;
}