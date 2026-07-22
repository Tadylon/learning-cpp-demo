#include <iostream>
#include <variant>
#include <cstdarg>

// 1. 递归终止函数（Base Case）
void print() {
    std::cout << "\n";
}

// 2. 变长参数模板函数
template<typename T, typename... Args> // Args... 声明类型参数包
void print(T first, Args... args) {    // args... 声明函数参数包
    std::cout << first << " ";
    print(args...);                    // args... 展开参数包并传给下一层递归
}

// 一元左折叠求和
template<typename... Args>
auto sum(Args... args) {
    return (... + args); // 展开为: ((arg1 + arg2) + arg3) ...
}

// 二元左折叠带初始值
template<typename... Args>
void printAll(Args... args) {
    (std::cout << ... << args) << '\n'; // 利用 std::cout 的 << 运算符连续打印
}

template<class... Ts> 
struct overloaded : Ts... { 
    using Ts::operator()...; // 展开 using，继承所有基类的 operator()
};

// C++17 自动推导指南
template<class... Ts> 
overloaded(Ts...) -> overloaded<Ts...>;

void doSomething(int code) {
    if (code == 1) throw std::runtime_error("Known runtime error");
    if (code == 2) throw 404; // 抛出了非 std::exception 的类型
}

double average(int count, ...) {
    va_list args;
    va_start(args, count); // 初始化，指向 count 后面的第一个参数

    double sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += va_arg(args, double); // 提取下一个 double 类型的参数
    }

    va_end(args); // 清理资源
    return count > 0 ? sum / count : 0.0;
}

int main() {
    // 变长参数模板函数
    print(1, 2.5, "Hello", 'c'); // 输出: 1 2.5 Hello c

    // 一元左折叠求和
    auto result = sum(3132,3123,3532);
    std::cout << "the result of sum is : " << result << "\n";

    // 二元左折叠带初始值
    printAll("hello \n","test" , "\n", "hello wine !");
    printAll("Age: ", 25, ", Score: ", 98.5);  // 输出: Age: 25, Score: 98.5

    std::variant<int, std::string> var = "Hello Variant";

    std::visit(overloaded {
        [](int x) { std::cout << "Int: " << x << "\n"; },
        [](const std::string& s) { std::cout << "String: " << s << "\n"; }
    }, var);


    try {
        doSomething(2);
    } 
    catch (const std::exception& e) {
        std::cout << "Standard exception: " << e.what() << "\n";
    } 
    catch (...) { // 捕获包括 int、自定义类型在内的所有其他异常
        std::cout << "Caught unknown exception!\n";
    }


    // 必须确保传入的类型与 va_arg 提取的类型完全一致（例如传递 double 浮点数）
    std::cout << average(3, 10.0, 20.0, 30.0) << "\n"; // 输出: 20

    return 0;

}