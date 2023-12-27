#include <utility>

template <typename T> void g(T &&val) {}

int main(int argc, char const *argv[])
{
    int i = 0; const int ci = i;


    g(i = ci);

    return 0;
}
