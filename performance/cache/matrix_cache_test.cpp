#include <iostream>
#include <chrono>
// using namespace std;
const int N = 4096;

static int matrix[N][N];

int main() {
    
    // 初始化
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            matrix[i][j] = i + j;
    
    // 测试1：行优先（缓存友好）
    auto start = std::chrono::high_resolution_clock::now();
    long long sum1 = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum1 += matrix[i][j];
    auto end = std::chrono::high_resolution_clock::now();
    auto time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "line by priority: " << time1 << "ms" << std::endl;
    
    // 测试2：列优先（缓存不友好）
    start = std::chrono::high_resolution_clock::now();
    long long sum2 = 0;
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            sum2 += matrix[i][j];
    end = std::chrono::high_resolution_clock::now();
    auto time2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "list by priority: " << time2 << "ms" << std::endl;
    
    std::cout << "performance difference : " << (double)time2 / time1 << " times !" << std::endl;
    return 0;
}