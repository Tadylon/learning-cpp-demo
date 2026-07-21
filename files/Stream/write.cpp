#include <iostream>
#include <fstream>

// using namespace std;

void test01()
{
	std::ofstream ofs;
	ofs.open("test.txt", std::ios::out);

	ofs << "姓名：张三" << std::endl;
	ofs << "性别：男" << std::endl;
	ofs << "年龄: 18" << std::endl;

	ofs.close();
}

int main() {

	test01();

	system("pause");

	return 0;
}


