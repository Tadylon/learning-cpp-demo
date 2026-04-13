#include <iostream>
#include <string>

// 基类 Animal
class Animal {
public:
    // 虚函数 sound，为不同的动物发声提供接口
    virtual void sound() const {
        std::cout << "Animal makes a sound" << std::endl;
    }
    
    // 虚析构函数确保子类对象被正确析构
    virtual ~Animal() { 
        std::cout << "Animal destroyed" << std::endl; 
    }
};

// 派生类 Dog，继承自 Animal
class Dog : public Animal {
public:
    // 重写 sound 方法
    void sound() const override {
        std::cout << "Dog barks" << std::endl;
    }
    
    ~Dog() {
        std::cout << "Dog destroyed" << std::endl;
    }
};

// 派生类 Cat，继承自 Animal
class Cat : public Animal {
public:
    // 重写 sound 方法
    void sound() const override {
        std::cout << "Cat meows" << std::endl;
    }
    
    ~Cat() {
        std::cout << "Cat destroyed" << std::endl;
    }
};

//学生类
class Student {
public:
    Student(){
        std::cout << "Student function in using " << std::endl;

    }
    ~Student(){
        std::cout << "Student function in destruction " << std::endl;
    }
	void setName(std::string name) {
		m_name = name;
	}
	void setID(int id) {
		m_id = id;
	}

	void showStudent() {
		std::cout << "name:" << m_name << " ID:" << m_id << std::endl;
	}
public:
	std::string m_name;
	int m_id;
};


// 测试多态
int main() {
    Animal* animalPtr;  // 基类指针

    // 创建 Dog 对象，并指向 Animal 指针
    animalPtr = new Dog();
    animalPtr->sound();  // 调用 Dog 的 sound 方法
    delete animalPtr;    // 释放内存，调用 Dog 和 Animal 的析构函数

    // 创建 Cat 对象，并指向 Animal 指针
    animalPtr = new Cat();
    animalPtr->sound();  // 调用 Cat 的 sound 方法
    delete animalPtr;    // 释放内存，调用 Cat 和 Animal 的析构函数

	Student stu;
	stu.setName("enthsu wine");
	stu.setID(250);
	stu.showStudent();
    system("pause");

    return 0;
}