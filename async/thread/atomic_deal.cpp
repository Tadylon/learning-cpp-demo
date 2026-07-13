#include <iostream>
#include <thread>
#include <mutex>
#include <atomic> // 引入原子库
#include "../chrono/standard_time.h"


int mtxcounter = 0;
std::mutex mtx;

void mtxincrease() {
    for (int i = 0; i < 100000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // 加锁
        mtxcounter++; // 安全，但每次都要加锁解锁，开销大
    }
}

void mutextest() {
    Timer timer("mutex_deal");
    std::thread t1(mtxincrease);
    std::thread t2(mtxincrease);
    t1.join();
    t2.join();
    
    std::cout << "Final counter: " << mtxcounter << std::endl; 
}


std::atomic<int> atocounter(0); // 声明 counter 为原子变量

void atoincrease() {
    for (int i = 0; i < 100000; ++i) {
        atocounter++; // 底层自动转换为 CPU 原子指令，不需要加锁！
    }
}

void atomoctest() {
    Timer timer("atomic_deal");
    std::thread t1(atoincrease);
    std::thread t2(atoincrease);
    t1.join();
    t2.join();
    
    std::cout << "Final counter: " << atocounter << std::endl; // 绝对是 200000
}

int main() {
    std::cout << "the mutex dealing begin ... \n";
    mutextest();
    std::cout << "the atomic dealing begin ... \n";
    atomoctest();
    return 0;
}