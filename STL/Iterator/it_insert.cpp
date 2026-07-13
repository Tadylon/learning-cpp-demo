#include <iostream>
#include <vector>
#include <list>

template<typename T>
void PrintIterator(T begin , T end) {
    std::cout << "the value of this iterator is : ";
    for (auto it = begin; it != end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template<typename Container>
void PrintContainer(const Container& container) {
    std::cout << "the elements of this container is : ";
    for (const auto& el : container) {
        std::cout << el;
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> vec = {1, 2, 3};
    PrintContainer(vec);
    PrintIterator(vec.begin(),vec.end());
    std::list<int> lst;
    PrintIterator(lst.begin(),lst.end());
    
    std::list<double> doulst = {1.1, 2.2, 3.3};
    PrintIterator(doulst.begin(), doulst.end());   // 打印整个 list
    PrintContainer(doulst);


    // 1. back_inserter：在末尾插入
    std::copy(vec.begin(), vec.end(), std::back_inserter(lst));
    // lst: 1, 2, 3

    // 2. front_inserter：在开头插入（适用于list/deque）
    std::copy(vec.begin(), vec.end(), std::front_inserter(lst));
    // lst: 3, 2, 1, 1, 2, 3

    // 3. inserter：在指定位置插入
    auto pos = lst.begin();
    std::advance(pos, 2);
    std::copy(vec.begin(), vec.end(), std::inserter(lst, pos));
    return 0;
}
