#include <iostream>
#include <string>

using MYFUNC = int (*)(int widht ,int height);

int add_func(int a,int b){
    std::cout <<"the result is :" << a+b <<std::endl;
    return a+b;
}

int less_func(int a,int b){
    std::cout <<"the result is :" << a-b <<std::endl;
    return a-b;
}

void someFunction(int (*func)(int, int), int first , int second) {
    int result = func(first, second);  // 调用传入的函数
    std::cout << "the result is : " << result << std::endl;
}

int main(){
    auto test = add_func;
    MYFUNC test_2;
    std::cout << sizeof(test) << std::endl;
    auto add_result = test(10,20);
    std::cout << add_result << std::endl;
    // add_func(10,20);
    test_2 = less_func;
    auto less_result = test_2(30,10);
    std::cout << less_result << std::endl;

    someFunction(add_func,5,7);  // 传递函数指针，不是调用add函数
    system("pause");
    return 0;
}