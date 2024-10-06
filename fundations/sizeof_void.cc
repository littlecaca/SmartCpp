#include <stdio.h>
#include <utility>
#include <algorithm>

class Empty
{

};

int main(int argc, char const *argv[])
{
    // void类型实例不包含任何信息，
    // 但是当我们声明该类型的实例时，它必须在内存种占有一定空间，
    // 至于占用多少，由编译器决定，gcc中是1
    // printf("%lld\n", sizeof(void));

    printf("%lld\n", sizeof(Empty));
    printf("%lld\n", sizeof Empty());
    return 0;
}
