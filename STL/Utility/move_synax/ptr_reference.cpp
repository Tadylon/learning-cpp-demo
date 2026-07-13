#include <iostream>
#include <string>

void allocateMemory(int*& ptr) { // 传入指针的引用
    ptr = new int[100];          // 修改外部的指针本身
}

int main()
{

    int* p = nullptr;
    allocateMemory(p); // p 现在指向有效的堆内存
    
}