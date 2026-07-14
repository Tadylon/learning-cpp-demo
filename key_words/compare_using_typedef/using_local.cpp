#include "print_obj.h"

int* test() {
    using int_ptr = int*; // 完全合法，仅限本函数内
    static int_ptr p = new int(5);
    return p;
}

int main()
{
    auto ptr = test();
    cout__(*ptr);
    int* & refptr = ptr;
    cout__(refptr);
    cout__(*refptr);
    cout__("-----------------------");
    cout__("\n");
    delete ptr;
    cout__(*ptr);
    return 0;
}