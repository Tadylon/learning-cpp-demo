#include <iostream>
#include <string>

class ConfigManager {
public:
    static ConfigManager& getInstance() {
        static ConfigManager instance;
        return instance;
    }

    // 禁用拷贝
    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

    // 实践应用：设置和获取配置
    void setConfig(const std::string& key, const std::string& value) {
        m_configValue = value; // 简化示例，只存一个值
        std::cout << "设置配置: " << key << " = " << value << std::endl;
    }

    std::string getConfig() {
        return m_configValue;
    }

private:
    ConfigManager() { std::cout << "--- 配置文件管理器已初始化 ---" << std::endl; }
    std::string m_configValue;
    // uint32_t ptr ;
};

// 模拟在不同函数中使用同一个实例
void moduleA() {
    ConfigManager::getInstance().setConfig("Theme", "Dark");
}

void moduleB() {
    std::cout << "模块B读取到的配置: " << ConfigManager::getInstance().getConfig() << std::endl;
}



int main()
{
    class Singleton {
    public:
        // 3. 静态访问接口
        static Singleton& getInstance()
        {
            // C++11 标准保证：多线程下局部静态变量的初始化是线程安全的
            static Singleton instance;
            return instance;
        }

        // 2. 禁用拷贝构造和赋值操作符
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

        void doSomething()
        {
            std::cout << "do something ! " << std::endl;
            return;
        }

    private:
        // 1. 私有化构造函数
        Singleton() { }
    };

    Singleton& s1 = Singleton::getInstance();
    s1.doSomething();
    Singleton::getInstance().doSomething();
    Singleton& s2 = s1;
    s2.doSomething();
    // Singleton s3 = s1; // 报错！这里需要调用拷贝构造函数，但它被 delete 了s
    // 错误用法演示：
    // Singleton s5;                // 编译错误：构造函数是私有的
    // Singleton s3 = s1;           // 编译错误：拷贝构造函数已禁用
    // Singleton* s4 = new Singleton(); // 编译错误：构造函数是私有的

    
    
    moduleA(); // 在模块A修改
    moduleB(); // 在模块B查看，发现数据是同步的
    
    return 0;
}

