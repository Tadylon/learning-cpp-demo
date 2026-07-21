#include <iomanip>
#include <iostream>

// using namespace std;

int main()
{
    std::cout << std::left << std::setw(10) << "Name" << std::setw(5) << "Age" << std::endl;
    std::cout << std::setfill('-') << std::setw(15) << "" << std::setfill(' ') << std::endl; // 填充字符粘性，setw只这一次
    std::cout << std::left << std::setw(10) << "Tom" << std::setw(5) << 18 << std::endl;


    return 0;
}











