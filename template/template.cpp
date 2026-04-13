#include <iostream>
#include <stdlib.h>
template<typename T>
void myswap(T & a,T & b){
    T temp = a;
    a = b;
    b = temp;

}

int x = 10;
int y = 20;

template< typename T>
T test(T a , T b){
    T number1 = a;
    T number2 = b;
    return number1+number2;
}


int main(){
    myswap<int>(x,y);

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    
    int final = test(x, y);

    std::cout << final << std::endl;
    double a =10.00;
    double change = test<double>(x, a);
    std::cout << "change is " << change << std::endl;

    system("pause");
    return 0;

}