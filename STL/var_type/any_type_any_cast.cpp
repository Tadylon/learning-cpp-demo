#include <iostream>
#include <any>
#include <string>
#include <variant>


int main(){
    std::any any_var = 124;
    {
        int& int_var = std::any_cast<int&>(any_var);
        // std::cout << "the value of any_var : " << any_var.type()== typeid(std::string) << std::endl;
        std::cout << "the value of any_var : " << int_var << std::endl;
    }
    
    {
        any_var = std::string("CHero");
        // any_var = "CHero"; 
        //上面这个代码会一直出现报错提示，这是为什么，不能够进行隐式转换吗。

        std::string&  data = std::any_cast<std::string&>(any_var);
        // std::string string_var = std::any_cast<std::string>(any_var);
        // std::cout << "the value of any_var : " << any_var.type()== typeid(std::string) << std::endl;
        // std::cout << "the value of any_var : " << std::any_cast<std::string>(any_var)<< std::endl;
        // auto data = std::string(any_var);
        std::cout << "the value of any_var : " << data << std::endl;
    }

    std::any data ;
    std::cout << sizeof(std::any) << std::endl;
    std::cout << sizeof(std::variant<std::string, int64_t>) << std::endl;

    return 0;
}


