#include <iostream>

// 假设有这个函数
int add(int a, int b) {
    return a + b;
}

// 用法1：把函数名传递给另一个函数
void someFunction(int (*func)(int, int), int first , int second) {
    int result = func(first, second);  // 调用传入的函数
    std::cout << "the result is : " << result << std::endl;
}

int main(){
    someFunction(add,5,7);  // 传递函数指针，不是调用add函数
    
    // 用法2：转换函数指针类型
    typedef int (*MathFunc)(int, int);
    
    MathFunc mathFunc = (MathFunc)add;  // 类似你的代码
    int stream_out = mathFunc(5,7);
    std::cout <<"stream_out is : "<< stream_out << std::endl;
    system("pause");
    return 0;
}