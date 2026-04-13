#include <iostream>

using namespace std;


int main(){
	//水仙花数：一个三位数，每个位上的数字的三次幂之和等于它本身
	//用do.....while求出所有三位数中的水仙花数
	int num = 100;
	do{
		int a = 0;
		int b = 0;
		int c = 0;
		a = num % 10;
		b = num / 10 % 10;
		c = num / 100;
		if(num == a*a*a + b*b*b + c*c*c ){
			cout << num << endl;
		}
		num++;

	} while (num < 1000);
	
    system("pause");
	return 0;
}