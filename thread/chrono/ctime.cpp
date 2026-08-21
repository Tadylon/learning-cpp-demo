#include <iostream>
#include <ctime>

// using namespace std;

int main( )
{
    // 基于当前系统的当前日期/时间
    time_t now = time(0);
    std::cout << "1970 to now the seconds is :" << now << std::endl;


    // 把 now 转换为字符串形式
    char* dt = ctime(&now);
    std::cout << "local data and time : " << dt << std::endl;
    
    tm *ltm = localtime(&now);
    dt = std::asctime(ltm);
    std::cout << "local data and time : "<< dt << std::endl;
    
    std::cout << "year  : "<< 1900 + ltm->tm_year << std::endl;
    std::cout << "month : "<< 1 + ltm->tm_mon<< std::endl;
    std::cout << "data  : "<<  ltm->tm_mday << std::endl;
    std::cout << "time  : "<< ltm->tm_hour << ":";
    std::cout << ltm->tm_min << ":";
    std::cout << ltm->tm_sec << std::endl;

    // 把 now 转换为 tm 结构
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    std::cout << "UTC data and time : "<< dt << std::endl;
    return 0;
}