#include <iostream>
#include <list>
#include <iterator>
#include <map>
#include <vector>


int main()
{
    std::list<int> lst = {1, 2, 3, 4, 5};
    auto it = lst.end();
    --it;  // 现在指向最后一个元素
    while (it != lst.begin()) {
        std::cout << *it << " ";  // 5 4 3 2
        --it;
    }
    std::cout << *it;  // 1
    std::cout << std::endl;  // 1

    return 0;
}
