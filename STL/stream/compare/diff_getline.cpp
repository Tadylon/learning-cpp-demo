#include <iostream>
#include <string>
#include <vector>

#include "print_obj.h"

//compare the std::getline with std::cin.getline()
//what the difference between this two

int main()
{

    //std::getline(std::cin, str, ',');
    std::string line;
    std::getline(std::cin, line); // 读取一整行，安全且不容易内存溢出
    cout__(line);


    //std::cin.getline(char* s, int n)
    char buf1[10];
    char buf2[10];
    std::cin.getline(buf1, 10); // 输入 "Hello" 后回车
    cout__(buf1);
    // 此时 buf1 存了 "Hello\0"，缓冲区的 '\n' 被清理掉了。
    
    std::cin.getline(buf2, 10); // 正常运行，程序会停下来等待你输入 buf2 的内容。
    cout__(buf2);
    
    return 0;
}
















