#include <iostream>
#include <iterator>

int main()
{

    // 输入流迭代器示例
    std::istream_iterator<int> in_it(std::cin);  // 从cin读取int
    std::istream_iterator<int> end;              // 默认构造为结束迭代器
    while (in_it != end) {
        std::cout << *in_it << " ";
        ++in_it;
    }
    std::cout << std::endl;
    return 0;
}