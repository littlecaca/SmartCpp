#include <utility>

template <typename T> void g(T val) {}
template <typename T> void g2(const T &val) {}

int main(int argc, char const *argv[])
{
    int i = 0; const int ci = i;

    g(i);
    g(ci);
    g(i * ci);
    
    g2(i);
    g2(ci);
    g2(i * ci); // T = `int`! I thought it would be `int &&`

    return 0;
}
