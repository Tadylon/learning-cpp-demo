#include <iostream>
#include <functional>
#include <string>


auto test_lambda =[](auto x){
    std::cout << "This is a lambda ! " <<std::endl;
    std::cout << "the value of result is : " << x * 2 << std::endl;
    return 2 * x;
};

using intFuncPtr = decltype(test_lambda);

//the third way
//使用 std::function + using
using IntCallback = std::function<void(int)>;
using FloatCallback = std::function<void(float)>;

auto callbackfunc = [](auto res){
    std::cout << "this is a callback function with void return value !" << std::endl;
    std::cout << "the value of result is : " << res * 2 << std::endl;
};

// 方式3：使用模板别名（更灵活）
template<typename T>
using Processor = std::function<T(T)>;

int main()
{

    int (*funcPtr)(int) = test_lambda;
    int result = funcPtr(10);  // 20

    //the second function
    //using name type-alias
    intFuncPtr sameLambda = test_lambda;
    sameLambda(65);
    sameLambda(65.343);

    //
    IntCallback test_int = callbackfunc;
    test_int(23);
    FloatCallback test_float = callbackfunc;
    test_float(23.3243);
    return 0;
}