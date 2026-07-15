#include <iostream>
#include <string>

int main() {
        int i;
        char str[20];
        std::string s1;
        std::cout << "input string : ";
        std::cin >> s1;
        std::cout << "s1 = " << s1 << std::endl;

        std::cout << "input both int and string : ";
        std::cin >> i >> str;
        std::cout << "i = " << i << std::endl;
        std::cout << "str = " << str << std::endl;
        
        char str1[20];
        std::cout << "input string : ";
        std::cin >> str1;
        std::cout << "str1 = " << str1 << std::endl;
        
        return 0;
}