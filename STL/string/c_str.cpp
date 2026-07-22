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
    printf("using printf: %s\n", str.c_str());
    printf("using printf: %s\n", cstr);

    // 3. 获取字符串长度
    std::cout << "the length of string : " << sizeof(str) << std::endl;
    std::cout << "the length of string : " << strlen(cstr) << std::endl;

    // 4. 用于文件操作
    std::string filename = "a.txt";
    // FILE* file = fopen((char*)filename, "r");
    FILE* file = fopen(filename.data(), "r+");
    if (file) {
        // 文件操作
        std::cout << file << "\n";
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            std::cout << buffer;   // fgets 保留换行符，所以不用加 endl
        }

        fclose(file);
    }

    return 0;
}