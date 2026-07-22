#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <format>

#include "standard_time.h"

int main()
{
    std::string name = "Alice";
    int age = 25;
    double score = 98.5432;

    {
        Timer Time{};
        // ❌ 1. std::stringstream：代码繁琐、充满了 << 符号和杂乱的格式控制符
        std::ostringstream oss;
        oss << name << " (Age: " << age << ", Score: " << std::fixed << std::setprecision(2) << score << ")";
        std::string s1 = oss.str();
        
    }
    
    {
        Timer Time{};
        // ⚠️ 2. std::to_string：无法直接控制精度，且字符串拼接会产生多份临时对象
        std::string s2 = name + " (Age: " + std::to_string(age) + ", Score: " + std::to_string(score) + ")"; 
        // 缺点：score 会强制变成 "98.543200"（固定 6 位小数），而且写法非常臃肿
        
    }

    {
        Timer Time{};
        // ✅ 3. C++20 std::format：Python 风格，直观且优雅
        std::string s3 = std::format("{} (Age: {}, Score: {:.2f})", name, age, score);
    }

    return 0;
}


















