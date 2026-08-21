#pragma once
#include <iostream>
#include <chrono>
#include <string>

class Timer {
private:
    std::string m_name;
    // 工业级 C++ 统一使用 steady_clock 确保时钟单调递增，不会因系统自动校时而倒流
    std::chrono::time_point<std::chrono::steady_clock> m_start;

public:
    explicit Timer(std::string name) 
        : m_name(std::move(name)), m_start(std::chrono::steady_clock::now()) {}

    ~Timer() {
        auto end = std::chrono::steady_clock::now();
        // 使用 double 提高精度，避免 float 导致的微秒级精度丢失
        std::chrono::duration<double, std::milli> duration = end - m_start;
        
        // 建议：实际项目中通常将数据写入日志文件，而不是直接 std::cout
        std::clog << "[" << m_name << "] Took: " << duration.count() << " ms\n";
    }
};