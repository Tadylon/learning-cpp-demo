#include <iostream>
#include <variant>
#include <string>


int main(){
    std::variant< std::string , int32_t > data;

    std::cout << "the size of string : " << sizeof(std::string) << std::endl;
    std::cout << "the size of int : " << sizeof(int32_t) << std::endl;
    std::cout << "the size of variant : " << sizeof(data) << std::endl;


    data = "cherno";
    auto variant_string_data = std::get<std::string>(data);
    std::cout << data.index() << std::endl;
    std::cout << std::get_if<std::string>(&data) << std::endl;
    
    std::cout << variant_string_data << std::endl;
    
    data = 1235;
    auto variant_int_data = std::get<int>(data);
    std::cout << data.index() << std::endl;
    std::cout << std::get_if<std::string>(&data) << std::endl;
    std::cout << variant_int_data << std::endl;

    return 0;
}















