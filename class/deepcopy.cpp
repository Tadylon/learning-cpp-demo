#include <iostream>
using namespace std;
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
    cout << "this is b : " << b.data << "  " <<  b.size << endl;
    cout << "this is a : " << x->data << "  " <<  x->size << endl;
    Buffer c = b;

    //print
    cout << "this is c : " << c.data << "  " <<  c.size << endl;
}

int main(){
    buildClass();

    system("pause");
    
    return 0;
}