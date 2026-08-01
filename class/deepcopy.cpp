#include <iostream>
#include <cstring>
#include <cstdlib>

class Buffer {
public:
    char * data;
    int size;

    //this is constructor
    Buffer(const char *value) {
        size = strlen(value) + 1;
        data = new char[size];
        //copy size
        memcpy(data, value, size); // 真正把 "hello" 拷进去
    }

    // deepcopy constructor
    Buffer(const Buffer& other) {
        // 1. 申请新的内存
        size = other.size;
        data = new char[size]; 
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }

    }
    //this is destructor function
    ~Buffer() {
        delete[] data; // 释放内存
    }
};

void buildClass(){
    const char * test = "hello";

    Buffer b(test);
    Buffer* x = new Buffer(b);
    //print
    std::cout << "this is b : " << b.data << "  " <<  b.size << std::endl;
    std::cout << "this is a : " << x->data << "  " <<  x->size << std::endl;
    Buffer c = b;

    //print
    std::cout << "this is c : " << c.data << "  " <<  c.size << std::endl;
}

int main(){
    buildClass();

    system("pause");
    
    return 0;
}