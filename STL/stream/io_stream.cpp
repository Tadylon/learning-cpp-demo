#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

#include "print_obj.h"

struct Point { int x, y; };
std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "(" << p.x << "," << p.y << ")";
}
std::istream& operator>>(std::istream& is, Point& p) {
    return is >> p.x >> p.y; // 支持连续输入 "3 4"
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    //真的不能使用printf吗？
    printf("hello ! \n");
    
    cout__("hello");


    // std::cerr << "wrong \n";
    std::clog << "something happened ! \n";
    double pi = 3.1415926;
    // 固定2位小数，右对齐占10格
    std::cout << std::fixed << std::setprecision(2) 
              << std::setw(10) << pi << std::endl; // 输出"      3.14"
    // setw只生效一次，下次输出pi如果不写setw，宽度就失效了

    cline__("---------------------------\n");
    int age; 
    std::string name;
    std::cin >> age;        // 输入"25\n"，换行符留在缓冲区
    std::cin.clear();
    std::cin.ignore(1024,'\n');
    cout__(age);
    
    cline__("---------------------------\n");
    std::getline(std::cin, name); // 直接读到空串，因为换行符被立即消费了
    cout__(name);
    std::getline(std::cin, name); // 直接读到空串，因为换行符被立即消费了
    cout__(name);
    return 0;
}