#include <stdio.h>
#include <malloc.h>

// 被打桩的程序
int main()
{
    int *p = malloc(32);
    free(p);
    return 0;
}
