#include <iostream>
#include <thread>

// 1. 函数指针
void hello() {
    std::cout << "Hello from function pointer!" << std::endl;
}

// 3. 函数对象
class Greeter {
public:
    void operator()() {
        std::cout << "Hello from function object!" << std::endl;
    }
};

int main() {
    // 1. 使用函数指针创建线程
    std::thread t1(hello);

    // 2. 使用 Lambda 表达式创建线程
    std::thread t2([]() {
        std::cout << "Hello from lambda!" << std::endl;
    });

    // 3. 使用函数对象创建线程
    Greeter greeter;
    std::thread t3(greeter);

    // 等待所有线程结束
    t1.join();
    t2.join();
    t3.join();
    system("pause");
    return 0;
}