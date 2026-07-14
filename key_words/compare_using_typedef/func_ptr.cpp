#include <iostream>
#include <stdio.h>
#include "print_obj.h"


typedef void (*tFuncType)(int&, double&);

using uFuncType = void (*)(int&, double&);

void swap(int& info, double& num) {
    auto temp = info;
    info = static_cast<int>(num);
    num = static_cast<double>(temp);
}
int main()
{

    uFuncType utestfunc = static_cast<uFuncType>(swap);
    
    tFuncType ttestfunc = static_cast<tFuncType>(swap);
    
    auto intnum = 32;
    auto doublenum = 23.232;
    cout__(intnum);
    cout__(doublenum);
    utestfunc(intnum,doublenum);
    cout__(intnum);
    cout__(doublenum);
    ttestfunc(intnum,doublenum);
    cout__(intnum);
    cout__(doublenum);

    return 0;
}






