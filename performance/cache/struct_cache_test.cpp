#include <iostream>
#include <vector>
#include <chrono>
// using namespace std;

const int N = 1000000;

// 缓存不友好的结构体
struct BadStruct {
    int id;
    char padding[64];  // 故意填充，让数据分散
    double value;
};

// 缓存友好的结构体
struct GoodStruct {
    int id;
    double value;
    char padding[56];  // 填充到同样大小，但顺序不同
};

int main() {
    std::vector<BadStruct> badData(N);
    std::vector<GoodStruct> goodData(N);
    
    // 初始化
    for (int i = 0; i < N; i++) {
        badData[i].id = i;
        badData[i].value = i * 1.5;
        goodData[i].id = i;
        goodData[i].value = i * 1.5;
    }
    
    // 测试1：缓存不友好（访问分散）
    auto start = std::chrono::high_resolution_clock::now();
    long long sum1 = 0;
    for (int i = 0; i < N; i++)
        sum1 += badData[i].id + (long long)badData[i].value;
    auto end = std::chrono::high_resolution_clock::now();
    auto time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "BadStruct: " << time1 << "ms" << std::endl;
    
    // 测试2：缓存友好（数据连续）
    start = std::chrono::high_resolution_clock::now();
    long long sum2 = 0;
    for (int i = 0; i < N; i++)
        sum2 += goodData[i].id + (long long)goodData[i].value;
    end = std::chrono::high_resolution_clock::now();
    auto time2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "GoodStruct: " << time2 << "ms" << std::endl;
    
    return 0;
}