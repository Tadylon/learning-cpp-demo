#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<std::string> src = {"a", "b", "c"};
    std::vector<std::string> dst;
    std::move(src.begin(), src.end(), std::back_inserter(dst));
    // src中的元素被移走，处于有效但未指定的状态
    return 0;
}













