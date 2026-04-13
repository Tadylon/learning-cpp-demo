#include <iostream>
#include <string>
using namespace std;


class Buffer {
public:
    int* data;
    Buffer(int value) {
        data = new int(value);
    }

    // 手动实现深拷贝构造函数
    Buffer(const Buffer& other) {
        // 1. 申请新的内存
        data = new int; 
        // 2. 复制实际的值
        *data = *(other.data); 
    }

    ~Buffer() {
        delete data; // 释放内存
    }
};

int main(){

    return 0;
}