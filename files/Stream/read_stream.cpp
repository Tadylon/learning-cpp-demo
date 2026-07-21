#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>

int main()
{
    char buf[80];
    std::ifstream in { "a.txt", std::ios::in };
    if (!in.is_open()) {
        std::cout << "fail to open a.txt" << std::endl;
        return EXIT_FAILURE;
    }
    
    while(in.getline(buf, sizeof(buf)))  {
        std::cout << buf << std::endl;
    }
    
    std::ifstream input { "a.txt", std::ios::in };
    std::string line;
    while (std::getline(input,line)) {
        std::cout << line << std::endl;
    }
    in.close();
    // while (in.get(buf, sizeof(buf))) {
    //     std::cout << buf << std::endl;
    // }
    // in.close();
    return EXIT_SUCCESS;
}