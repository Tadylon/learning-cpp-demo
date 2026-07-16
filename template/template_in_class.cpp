#include <iostream>
#include <string>
// using namespace std;

#include "print_obj.h"
//类模板
template<class NameType, class AgeType> 
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		std::cout << "name: " << this->mName << "\n" << "age: " << this->mAge << std::endl;
	}
public:
	NameType mName;
	AgeType mAge;
};

template <typename T, int Size>
class Array {
private:
    T arr[Size] = {};
public:
    T& operator[](int idx) { 
        return arr[idx]; 
    }

    const T& operator[](int idx) const { 
        return arr[idx]; 
    }

    void* getArr() {
        return arr;
    }

    std::array<T, Size> to_std_array() const {
        std::array<T, Size> ret;
        for (int i = 0; i < Size; ++i) ret[i] = arr[i];
        return ret;
    }
    
    Array() = default;

    void print() const {
        std::cout << "[";
        for (int i = 0; i < Size; ++i) {
            std::cout << arr[i];
            if (i != Size - 1) std::cout << ", ";
        }
        std::cout << "]";
    }
};


template<typename T, int Size>
std::ostream& operator<<(std::ostream& os, const Array<T, Size>& arr) {
    os << "[";
    for (int i = 0; i < Size; ++i) {
        os << arr[i];
        if (i != Size - 1) os << ", ";
    }
    os << "]";
    return os;
}


int main() {
    // 指定NameType 为string类型，AgeType 为 int类型
    Person<std::string, int> P1("Monkey King ", 999);
    P1.showPerson();
    cline__("----------\n");
    
    Array<int, 10> myArray; // 必须指明 <int, 10>
    //this is a ptr
    cout__(myArray.getArr());

    std::cout << myArray << std::endl;
    myArray.print();
	return 0;
}


