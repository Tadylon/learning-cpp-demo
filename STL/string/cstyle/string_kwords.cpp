#include <iostream>
#include <cstring>

#include "print_obj.h"

//这两个是操作string的
char* strcpy(char* dest, const char* src);

int strcmp(const char* str1, const char* str2);

//这里介绍一下操作memory的函数
//memory 复制
void* memcpy(void* dest, const void* src, size_t count);

//memory 移动
void* memmove(void* dest, const void* src, size_t count);

//memory 初始化
void* memset(void* dest, int ch, size_t count);

int main()
{
    char src[] = "Hello";
    char dest[10];
    strcpy(dest, src); // dest 变成了 "Hello"
    strncpy(dest, src, sizeof(dest) - 1);

    auto res1 = strcmp("apple", "apple"); // 返回 0
    std::cout << "the result is : " << res1 << std::endl;
    auto res2 = strcmp("apple", "banana"); // 返回负数（'a' < 'b'）
    std::cout << "the result is : " << res2 << std::endl;
    auto res3 = strcmp("banana", "apple"); // 返回正数（'b' > 'a'）
    std::cout << "the result is : " << res3 << std::endl;


    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5];
    int arr3[5];
    PrintContainer(arr1);
    PrintContainer(arr2);
    PrintContainer(arr3);
    // 复制整个数组：5 个 int，每个 int 4 字节，共 20 字节
    memcpy(arr2, arr1, sizeof(arr1));
    PrintContainer(arr2);
    memmove(arr3, arr1, sizeof(arr1));
    cout__("the contant of arr1 after move : ");
    PrintContainer(arr1);
    PrintContainer(arr3);
    
    cout__("--------------------\n");
    //这里再详细认识一下memset函数
    int arrmemset[100];
    cout__("the initize of arrmemset : ");
    PrintContainer(arrmemset);
    // 把 100 个 int 的内存全部清零
    memset(arrmemset, 0, sizeof(arrmemset));
    
    cout__("the memory set zero of arrmemset : ");
    PrintContainer(arrmemset);

    return 0;
}












