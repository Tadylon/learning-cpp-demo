#include <iostream>
#include <cstddef>

// const std::ssize()
enum class OpenModel { 
    input = 4, 
    output, 
    append
    };

enum class Color { red, yellow, green };
enum { floatPrec = 6, doublePrec = 10 };


int count = 11;         // 全局（::）的 count

class A {
public:
	inline static int count = 21;   // 类 A 的 count（A::count）
};                                  //直接使用class中的inline来进行class内声明

// int A::count = 21;
void PrintData(int& data)
{
    std::cout << "the data value : " << data << std::endl;
}

void Fun_Partial()
{
	int count = 31;     // 初始化局部的 count 为 31
	PrintData(count);

    count = 32;         // 设置局部的 count 的值为 32
	PrintData(count);
}

int& Fun_Global(int& global_data)
{
    global_data = 3232;
    return global_data;
}



int main() {
    std::cout << "the global data \n";
	::count = static_cast<int>(OpenModel::append);       // 测试 1：设置全局的 count 的值为 12
    PrintData(::count);
    
    std::cout << "the class data \n";
	A::count = 22;      // 测试 2：设置类 A 的 count 为 22
    PrintData(A::count);
    
    std::cout << "the class data \n";
	Fun_Partial();		        // 测试 3
    count = Fun_Global(count);
    PrintData(::count);

	return 0;
}