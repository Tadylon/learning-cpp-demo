#include <iostream>
// #include <string>

using MYFUNC = int (*)(int widht ,int height);

int add_func(int a,int b){
    return a+b;
    std::cout <<"the result is :" << a+b <<std::endl;
}

int less_func(int a,int b){
    return a-b;
    std::cout <<"the result is :" << a-b <<std::endl;
}

void someFunction(int (*func)(int, int), int first , int second) {
    int result = func(first, second);  // 调用传入的函数
    std::cout << "the result is : " << result << std::endl;
}

int main(){
    MYFUNC test {nullptr};
    test(10,20);

    test = less_func;
    test(30,10);

    someFunction(add_func,5,7);  // 传递函数指针，不是调用add函数

    return 0;
}