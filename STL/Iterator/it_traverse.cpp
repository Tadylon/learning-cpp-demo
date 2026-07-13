#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 方式1：传统for循环
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // 方式2：范围for循环（C++11，底层使用迭代器）
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    
    // 方式3：使用算法
    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;
    
    // 方式4：反向遍历
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        std::cout << *it << " ";  // 5 4 3 2 1
    }
    std::cout << std::endl;
    std::cin.get();
    return 0;
}