#include <iostream>

int main(int argc, char const *argv[])
{
    int x = 12;
    int &&x2 = 13;
    int &x3 = x;
    decltype((x)) y = x;
    decltype(auto) y2 = (x);
    decltype(x2) y3 = 21;
    decltype(x3) y4 = x;
    return 0;
}
