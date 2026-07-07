#include <iostream>
#include <cstdint>


union FloatBits {
    float f;
    uint32_t bits; // 无符号整数，与 float 大小相同
};

void inspect_float(float value) {
    FloatBits fb;
    fb.f = value;
    std::cout << "float: " << fb.f << std::endl;
    std::cout << "the sixteen of read : 0x" << std::hex << fb.bits << std::endl;
}

int main(){
    FloatBits a;
    a.bits = 30;
    inspect_float(a.f);
    system("pause");
    return 0;
}