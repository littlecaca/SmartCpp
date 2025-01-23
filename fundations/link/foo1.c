#include <stdio.h>

// foo1.c
int x = 12;     // 强符号
int y = 12;     // 强符号

void f(void);
int main()
{
        f();
        printf("x: 0llx%x, y: 0llx%x\n", (long long)&x, (long long)&y);
        printf("x = 0x%x, 0x%x\n", x, y);
        return 0;
}
