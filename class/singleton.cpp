#include <iostream>

class Singleton {
private:
    Singleton() {
        
    }                    // 私有构造函数
    static Singleton* instance;
    
public:
    static Singleton* getInstance() {
        if (!instance) {
            instance = new Singleton();
        }
        return instance;
    }
    
    Singleton(const Singleton&) = delete;     // 禁止拷贝
    Singleton& operator=(const Singleton&) = delete;
};

// 定义（分配内存空间，告诉链接器这个变量的地址）
// 这不是"访问"，而是"提供实现"
Singleton* Singleton::instance = nullptr;

class MathUtils {
    private:
    MathUtils() = delete;    // 禁止创建对象
    // 或设为私有：MathUtils() {}
    
    public:
    static double pi() { return 3.14159; }
    static int add(int a, int b) { return a + b; }
    static int square(int x) { return x * x; }
};


int main(){

    
    int y = 10;
    // 使用：只能通过类名调用
    MathUtils::add(3, 5);      // ✅
    // MathUtils obj;          // ❌ 编译错误
    int test = MathUtils::square(y);
    std::cout << "the square of y is : " << test << std::endl;


    //使用单例
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    std::cout << "Same instance: " << (s1 == s2) << std::endl;

    return 0;
}
