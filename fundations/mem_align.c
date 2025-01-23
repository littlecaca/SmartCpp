#include <stdio.h>

struct base
{
    int i;
    char a;
};

struct base3
{
    char a;
    int i;
} __attribute__((__packed__));


struct base4
{
    double d;
    char a;
};

struct base2
{
    char a;
    int i;
};

int main()
{
    printf("%lld, %lld\n", sizeof(struct base), sizeof(struct base2));
    printf("%lld, %lld\n", sizeof(struct base3), sizeof(struct base4));
    return 0;
}
