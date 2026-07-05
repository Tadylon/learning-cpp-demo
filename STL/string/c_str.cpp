// 在文件开头添加（必须在包含任何头文件之前）
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
// #include <stdio.h>
// #include <map>

int main()
{
    std::string str = "Hello World";

    // 1. 获取 C 风格字符串
    const char* cstr = str.c_str();

    // 2. 用于 C 标准库函数
    printf("使用 printf: %s\n", str.c_str());
    printf("使用 printf: %s\n", cstr);

    // 3. 获取字符串长度
    std::cout << "字符串长度: " << sizeof(str) << std::endl;
    std::cout << "字符串长度: " << strlen(cstr) << std::endl;

    // 4. 用于文件操作
    std::string filename = "test.txt";
    FILE* file = fopen(filename.c_str(), "r");
    if (file) {
        // 文件操作
        fclose(file);
    }

    return 0;
}