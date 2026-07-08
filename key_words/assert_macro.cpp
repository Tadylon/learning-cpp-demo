// #define NDEBUG          // 加上这行，则 assert 不可用
#include <assert.h>
#include <iostream>
#include <cstddef>


int main()
{

    int p = 232;
    p=NULL;
    assert( p != NULL );    // assert 不可用
    std::cout << "p != NULL\n"; 
    return 0;
}