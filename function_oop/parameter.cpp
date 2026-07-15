

#include "print_obj.h"
#include "standard_time.h"


void PrintSum(int a, int b) {
    std::cout << a << " + " << b << " = " << (a+b) << std::endl;
}

int main()
{
    int value = 0;
    int value_ = 0;
    // PrintSum(value++, value++);
    PrintSum(++value ,++value_);
    return 0;
}








