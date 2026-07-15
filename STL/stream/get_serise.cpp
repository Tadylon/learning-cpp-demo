#include <iostream>
#include <string>
#include "print_obj.h"


int main() {
        char szBuf[6] = "faff";
        char szBuf1[6] = "asfd";
        std::cout << "szBuf : ";
        cout__(szBuf);
        std::cout << "szBuf1 : ";
        cout__(szBuf1);

        // cline__("\n");

        std::cout << "please input number : ";
        // int32_t n = std::cin.get();        //特殊情况可使用get提取'\n'
        std::string n_string;
        
        std::cout << "pls input string : ";
        std::getline(std::cin,n_string);
        std::cout << "n_string : ";
        cout__(n_string);

        std::cout << "pls input number : ";
        int n = std::cin.get();
        std::cout << "n : ";
        cout__(n);
        char ch = std::cin.get(); // 假设输入 1
        std::cout << "ch : "<<  ch << "\n";          // 输出：1


        //2. 将std::get(szBuf1 , 6) 换成 std::getline()
        std::cin.getline(szBuf1, 6);
        std::cout << "szBuf1 : ";
        cout__(szBuf1);
        //专门使用一个来解决掉全部buffer
        
        cline__("----------------------\n");

        std::cin.getline(szBuf,sizeof(szBuf));
        // std::cout << n << std::endl;
        std::cout << "The received string is:" << szBuf << std::endl;
        //cout << "The received string is:" << szBuf1 << endl;
        
        return 0;
}