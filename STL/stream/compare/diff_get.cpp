#include <iostream>
#include <string>
#include <vector>

#include "print_obj.h"

//compare the std::cin.get() with std::cin.get()
//what the difference between this two

void test01()
{
    //std::cin.get()
    char ch1, ch2;
    ch1 = std::cin.get(); // 假设输入 "A" 后回车。此时 ch1 存了 'A'
    cout__(ch1);
    std::cin.clear();
    ch2 = std::cin.get(); // 此时 ch2 会直接读入刚才的回车符 '\n'，程序不会停下来等你输入
    cout__(ch2);

}


void test02()
{
    char buf1[10];
    char buf2[10];
    cout__(buf1);
    cout__(buf2);
    
    std::cin.get(buf1, 10); // 输入 "Hello" 后回车
    // 此时 buf1 中存了 "Hello\0"，但是换行符 '\n' 依然卡在缓冲区的第一位！
    cout__(buf1);
    
    //clear the buffer arean
    std::cin.clear();
    
    std::cin.get(buf2, 10); 
    cout__(buf2);
    // 这一句运行时，一上来就碰到了上次留下的 '\n'。
    // 函数认为“已经到换行了”，于是直接结束，buf2 变成空字符串，程序根本不给你第二次输入的机会。

}


int main()
{
    test01();
    //clear the buffer arean
    std::cin.clear();
    test02();
    
    return 0;
}







