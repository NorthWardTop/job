#include <stdio.h>

int main(int argc, char const *argv[])
{
    struct CAT_s{
        int ld;
        char Color;
        unsigned short Age;
        char *Name;
        void(*Jump)(void);
    }Garfield;
    printf("%d\n", sizeof(Garfield));


    return 0;
}
