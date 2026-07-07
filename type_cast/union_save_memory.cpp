#include <iostream>
#include <string>
#include <cstdint>


union Data {
    int32_t i;      // 4 字节（通常）
    float f;    // 4 字节
    double d;   // 8 字节
    char c;     // 1 字节
};

int main() {
    Data data ;
    std::cout << "the size of union data : " << sizeof(data) << " bytes " << std::endl; // 通常输出 8 (对齐到 double)
    
    // 赋值和访问
    data.i = 42;                // 写入 int
    std::cout << "out value of int: " << data.i << std::endl;   // 输出 42
    std::cout << "out value of float: " << data.f << std::endl; // 将 int 的内存解释为 float，输出垃圾值
    
    data.f = 3.14f;             // 现在写入 float
    std::cout << "the rewrite value of out float: " << data.f << std::endl; // 输出 3.14
    std::cout << "out int: " << data.i << std::endl;   // 浮点数的二进制解释为 int，输出垃圾值
    system("pause");
    return 0;
}