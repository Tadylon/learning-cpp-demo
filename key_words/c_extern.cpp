#include <cstddef>

#ifdef __cplusplus
extern "C" {
#endif

void *memset(void *, int, size_t);

#ifdef __cplusplus
}
#endif

#include <iostream>

int main()
{
    std::cout << "hello world" << std::endl;
    return 0;
}