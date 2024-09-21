#include <iostream>


using namespace std;

template <typename T1, typename T2>
auto func(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}



int main(int argc, char const *argv[])
{
    double a = 1.232;
    int b = 211;

    cout << func(a, b) << endl;

    return 0;
}
