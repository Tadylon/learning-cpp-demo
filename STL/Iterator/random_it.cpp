#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <array>


int main()
{
    std::vector<int> vec = {10, 20, 30, 40, 50};
    auto it = vec.begin();
    it += 2;           // 移动到索引2
    std::cout << *it;  // 30
    std::cout << it[1]; // 40（it之后的第1个元素）
    auto it2 = vec.end() - 1;  // 指向最后一个元素
    std::cout << it2 - it;     // 2（距离）
    return 0;
}