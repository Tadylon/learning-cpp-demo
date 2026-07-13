#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    // 输出流迭代器示例
    std::ostream_iterator<int> out_it(std::cout, " ");
    *out_it = 10;  // 输出10
    // std::cout << "the value of out_it is : " << *out_it << std::endl;
    ++out_it;
    *out_it = 20;  // 输出20

    std::cout << "\n-----------------\n";

    // 写法 2：这才是它的现代工业化标准用法（配合算法）
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // 把 vec 从头到尾的内容，“复制”到 out_it 中，相当于一锅端打印出来
    std::copy(vec.begin(), vec.end(), out_it); // 屏幕输出: 1 2 3 4 5

    return 0;
}




