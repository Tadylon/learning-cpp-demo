#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

auto sayHello = []() {
    std::cout << "Hello, Lambda!" << std::endl;
};



void ForEach(const std::vector<int>& values,const std::function<void(int)>& func) {
    for (int value : values) {
        func(value);
    }
}


int main(){

    sayHello(); // 调用

    int a = 200;
    std::vector<int> values = {1,2,3,543,6,32,};

    auto it =std::find_if(values.begin(),values.end(),[](int value){return value > 5;});
    std::cout << *it << std::endl;
    auto lambda_function = [&](int value) {std::cout << "Value : " << value << std::endl;
                                                            std::cout << "the number of a is : " << a << std::endl;};
    ForEach(values,lambda_function);
    std::cin.get();
    return 0;
}