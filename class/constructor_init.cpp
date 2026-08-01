#include <iostream>
#include <cstdlib>
// using namespace std;

class Person {
public:
	////传统方式初始化
	//Person(int a, int b, int c) {
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}

	//初始化列表方式初始化
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}
	void PrintPerson() {
		std::cout << "mA:" << m_A << std::endl;
		std::cout << "mB:" << m_B << std::endl;
		std::cout << "mC:" << m_C << std::endl;
	}
private:
	int m_A;
	int m_B;
	int m_C;
};


int main() {
	Person p(1, 2, 3);
	p.PrintPerson();
	system("pause");
	return 0;
}




