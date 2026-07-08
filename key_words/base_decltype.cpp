#include <iostream>
#include <type_traits>
#include <vector>
#include <iterator>


// 尾置返回允许我们在参数列表之后声明返回类型
template <typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
    // 处理序列
    return *beg;    // 返回序列中一个元素的引用
}


// 为了使用模板参数成员，必须用 typename
template <typename It>
auto fcn2(It beg, It end) -> typename std::remove_reference<decltype(*beg)>::type
{
    // 处理序列
    return *beg;    // 返回序列中一个元素的拷贝
}

int main()
{
    // int a = 23, b =32;
    std::vector<int> vectors = {23,244534,543,43};
    
    auto& test_function1 = fcn(vectors.begin(), vectors.end());
    auto test_function2 = fcn(vectors.begin(), vectors.end());
    
    std::cout << test_function1 << std::endl;
    std::cout << test_function2 << std::endl;

    return 0;
}