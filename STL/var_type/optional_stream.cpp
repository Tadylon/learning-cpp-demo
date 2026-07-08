#include <iostream>
#include <fstream>
#include <optional>
#include <string>


std::optional<std::string> ReadFileASString(const std::string& filepath)
{
    std::ifstream stream(filepath);
    if(stream)
    {
        std::string result;

        //read file 
        stream.close();
        return result;
    }

    return {};
}

int main() {
    auto data = ReadFileASString("data.txt");
    if (data.has_value()) {
        std::cout << "the value is : " << data->data() << std::endl;
    }
    else {
        std::cout << "the value is empty !" << std::endl;
    }
    return 0;
}