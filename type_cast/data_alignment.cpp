#include <iostream>
#include <cstdint>


struct PlayerData {
    int32_t id;       // 4字节
    float health; // 4字节
    char level;   // 1字节
}; // 考虑对齐，实际可能占用 12 字节

void sendOverNetwork(const char* buffer, size_t size) {
    // 模拟网络发送，网络只接收 char* 字节流
    std::cout << "Send the messages successfully\n" << size << " bytes of baked data ! " << std::endl;
}

int main() {
    PlayerData player = {1001, 98.5f, 'A'};

    // 核心操作：把结构体的地址 &player 强转为常量字符指针 const char*
    // 此时，编译器不再把这里看作结构体，而是看作包含 12 个 char 的裸数组
    const char* rawBytes = reinterpret_cast<const char*>(&player);

    // 完美对接网络接口
    sendOverNetwork(rawBytes, sizeof(PlayerData));
    system("pause");
    return 0;
}