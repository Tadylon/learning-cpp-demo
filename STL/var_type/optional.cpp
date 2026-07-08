#include <iostream>
#include <optional>
#include <string>

// 模拟一个查找用户的函数：可能找到，也可能找不到
std::optional<std::string> findUserName(int userId) {
    if (userId == 1) {
        return "Alice"; // 成功：直接返回对应类型，会自动隐式包装成 std::optional
    }
    return std::nullopt; // 失败：返回空状态（显式表示无数据）
}

int main() {
    auto result1 = findUserName(1);
    
    // 检查是否有值：方式 A（像布尔值一样判断）
    if (result1) { 
        // 获取值：方式 A（使用解引用操作符 *，类似指针，但不发生指针开辟）
        std::cout << "the name of user 1 : " << *result1 << std::endl; 
    }

    auto result2 = findUserName(2);
    
    // 检查是否有值：方式 B
    if (!result2.has_value()) {
        std::cout << "we can`t find user2" << std::endl;
    }

    // 安全获取值：方式 C（value_or：有值就拿值，没值就拿兜底默认值）
    std::string name = result2.value_or("we can`t find users");
    std::cout << "the name of user 2 : " << name << std::endl;
    system("pause");
    return 0;
}