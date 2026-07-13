#include <iostream>
#include <vector>
#include <array>

int main()
{
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    auto it = arr.begin();
    std::cout << "the value of it is : " << *it << std::endl;
    // 连续迭代器保证 &arr[0] + n == &arr[n]
    return 0;
}