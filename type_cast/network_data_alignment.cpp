#include <iostream>
#include <cstdint>
#include <cstddef>
// #pragma pack(1)
struct test{
    uint64_t test_01;
    uint64_t test_02;
};

struct alignas(16) PlayerData {
    test test_struct;
    uint64_t test_64int;
    double alignment;
    float health; // 4字节
    int32_t id;       // 4字节
    char level;   // 1字节
}; // 

void sendOverNetwork(const char* buffer, size_t size) {
    // 模拟网络发送，网络只接收 char* 字节流
    std::cout << "Send the messages successfully\n" << size << " bytes of baked data ! " << std::endl;
}

int main() {
    PlayerData player = {{2,3},400,10.4,10.3,10, 'A'};
    // 帮我们探查某个类型在当前系统下是按照几字节对齐的
    std::cout << alignof(int) << std::endl; // 输出 4
    std::cout << alignof(player) << std::endl; // 输出 4 (因为内部最大的是int)
    std::cout << "offsetof(test_struct): " << offsetof(PlayerData, test_struct) << std::endl; // 
    std::cout << "offsetof(test_64int): " << offsetof(PlayerData, test_64int) << std::endl;   // 
    std::cout << "offsetof(alignment): " << offsetof(PlayerData, alignment) << std::endl;     // 
    std::cout << "offsetof(health): " << offsetof(PlayerData, health) << std::endl;           // 
    std::cout << "offsetof(id): " << offsetof(PlayerData, id) << std::endl;                   // 
    std::cout << "offsetof(level): " << offsetof(PlayerData, level) << std::endl;             // 

    // 核心操作：把结构体的地址 &player 强转为常量字符指针 const char*
    // 此时，编译器不再把这里看作结构体，而是看作包含 12 个 char 的裸数组
    const char* rawBytes = reinterpret_cast<const char*>(&player);

    
    // 完美对接网络接口
    sendOverNetwork(rawBytes, sizeof(PlayerData));
    // #pragma pack(pop)
    system("pause");
    return 0;
}