#include <iostream>
#include <string>
#include "Windows.h"
using namespace std;

// 【Class 类】：定义了一个“动物”的模板
class Animal {
private:
    // 【Encapsulation 封装】：将变量设为私有(private)，外部不能直接改
    string name;

public:
    Animal(string n) : name(n) {}

    // 封装的接口：想改名字只能通过这个方法，我们可以在这里加逻辑检查
    void setName(string n) {
        if (!n.empty()) name = n;
    }

    string getName() const { return name; }

    // 【Polymorphism 多态的基础】：使用 virtual 关键字声明虚函数
    virtual void speak() const {
        cout << "某种动物在叫..." << endl;
    }
};

// 【Inheritance 继承】：猫和狗都是动物，继承 Animal
class Dog : public Animal {
public:
    //构造函数
    // 调用父类的构造函数
    Dog(string n) : Animal(n) {}
    //普通函数
    // 【Polymorphism 多态的体现】：重写(Override)父类的方法
    void speak() const override {
        cout << getName() << " 说: 汪汪汪!" << endl;
    }

    //没有析构函数，这是为什么
};

class Cat : public Animal {
public:
    //这是一个构造函数
    Cat(string n) : Animal(n) {}

    void speak() const override {
        cout << getName() << " 说: 喵喵喵~" << endl;
    }
    void walk(){
        cout << "walk walk ..." << endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    // 创建具体的对象
    Dog dog1("大黄");
    Cat cat1("小咪");
    dog1.speak();
    cat1.speak();
    // 展示多态的威力：
    // 我们用一个“父类指针”去指向不同的“子类对象”
    Animal* zoo[2];
    zoo[0] = &dog1;
    zoo[1] = &cat1;

    cout << "--- 动物园点名 ---" << endl;
    for (int i = 0; i < 2; i++) {
        // 同一个 speak() 指令，产生了不同的结果
        zoo[i]->speak(); 
    }

    return 0;
}