#include <cstring>

template<typename T>
class FiveRule
{
	FiveRule(const FiveRule& other) noexcept {
		//这是copy constructor
	}
	FiveRule& operator=(const FiveRule& other) noexcept {
		//这是copy assignment
	}
	
	FiveRule(FiveRule&& other) noexcept {
		//this is move constructor
	}
	FiveRule& operator=(FiveRule&& other) noexcept {
		//this is move assignment
	}
	
	~FiveRule() {
		//this is destructor
	}
};

class GoodString {
public:
    // 构造 & 析构
    GoodString(const char* str) : data(new char[strlen(str)+1]) { 
        strcpy(data, str); 
    }
    
    ~GoodString() { delete[] data; }

    // 拷贝构造（深拷贝）
    GoodString(const GoodString& other) : data(new char[strlen(other.data)+1]) {
        strcpy(data, other.data);
    }
    // 拷贝赋值（深拷贝）
    GoodString& operator=(const GoodString& other) {
        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data)+1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // 移动构造（窃取指针）—— 遵循五法则补充的
    GoodString(GoodString&& other) noexcept : data(other.data) {
        other.data = nullptr; // 把源对象置空
    }
    // 移动赋值（窃取指针）
    GoodString& operator=(GoodString&& other) noexcept {
        if (this != &other) {
            delete[] data;      // 释放自己的旧资源
            data = other.data;  // 偷过来
            other.data = nullptr;
        }
        return *this;
    }

private:
    char* data;
    //最佳实践是直接使用标准库中的std::string
};