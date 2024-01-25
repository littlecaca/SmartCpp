#include <iostream>
#include <gl/GL.h>
#include <deque>
using namespace std;

void fun(const int &i) {}
void fun(int &&i) {}

int main(int argc, char const *argv[])
{
    int i = 21;
    int &&j = 32;
    fun(std::move(i));
    fun(i * 21);
    fun(j);
    using tt = decltype(i);
    return 0;
}
