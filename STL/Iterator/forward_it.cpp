#include <iostream>
#include <iterator>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>


int main()
{
    std::forward_list<int> fl = {1, 2, 3, 4, 5};
    auto it = fl.begin();
    while (it != fl.end()) {
        *it *= 2;  // 可读写
        std::cout << "the value of now is : " << *it << std::endl;
        ++it;
    }
    return 0;
}
