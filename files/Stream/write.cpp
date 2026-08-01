#include <iostream>
#include <fstream>

// using namespace std;

void test01()
{
	std::ofstream ofs;
	ofs.open("test.txt", std::ios::out);

	ofs << "name   : zhangsan" << std::endl;
	ofs << "gender : man" << std::endl;
	ofs << "age    : 18" << std::endl;

	ofs.close();
}

int main() {

	test01();

	system("pause");

	return 0;
}


