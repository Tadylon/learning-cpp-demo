#include <iostream>
#include <vector>
#include <string>
#include <list>


int main()
{
    std::vector<int> vec = {1,2,4,6,3,5,23,34};
    std::list<std::string> strList = {"Le","Ni Hao","tady","wine"};
    // 使用auto（C++11及以后，推荐）
    auto it = vec.begin();

    // 显式声明
    std::vector<int>::iterator it1 = vec.begin();
    std::cout << "the value of it1 is : " << *it1 << std::endl;
    std::cout << "the value of it1 is : " << *(it1 + 6) << std::endl;

    std::vector<int>::const_iterator it2 = vec.cbegin();
    std::cout << "the value of it2 is : " << *it2 << std::endl;
    
    std::list<std::string>::iterator it3 = strList.begin();
    std::cout << "the value of it3 is : " << *++it3 << std::endl;
    std::cout << "the value of it3 is : " << *it3 << std::endl;
    return 0;
}
