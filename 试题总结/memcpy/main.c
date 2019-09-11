#include <stdio.h>


void *mymemcpy(void *src, void *dst, size_t len)
{
    int nchunks = len/sizeof(dst); //按照指针大小间隔copy
    int slice = len%sizeof(dst); //计算剩余的指针量

    unsigned long *s = (unsigned long*)src;
    unsigned long *d = (unsigned long*)dst;

    while (nchunks--)
        *d++ = *s++;
    
    while (slice)
        *(char*)d++ = *(char*)s++;
}


int main(int argc, char const *argv[])
{
    mymemcpy()
    return 0;
}
