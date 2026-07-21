#include <iostream>
#include <sstream>
#include <string>
#include <cstddef>
#include <cstdint>
#include <fstream>

#include "standard_time.h"

// using namespace std;

int main()
{
    
    std::ostringstream oss;
    std::string name = {"wine"};
    int32_t score = 88;
    auto elapsed = 423423.234f;
    oss << "User:" << name << ", Score:" << score << ", Time:" << elapsed << "ms";
    std::string result = oss.str(); // 一次性构建，避免多次 string 拷贝
    std::cout << result << "\0";


    std::ofstream file_text;
    file_text.open("a.txt",std::ios::app);
    
    if (file_text.is_open()) {
        file_text << "\0";
        file_text << oss.str() <<std::endl;
    }
    
    return 0;
}















