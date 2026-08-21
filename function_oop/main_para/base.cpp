#include <cstdio>
#include <cstring>

int main(int argc ,char* argv[])
{
    printf("argc = %d\n", argc);

    argv++;
    while (*argv){
        if (std::strcmp(*argv, "Aa") == 0){
            argv++;
            printf("A for apple\n");

        }else if (strcmp(*argv, "Bb") == 0){
            argv++;
            printf("B for ball\n");

        }else if (strcmp(*argv, "Cc") == 0){
            argv++;
            printf("C for cat\n");

        }else if (strcmp(*argv, "Dd") == 0){
                printf("in d\n");
            argv++;
            printf("D for dog\n");
        }
    }
}