#include <random>
#include <iostream>

using namespace std;

unsigned int genRandom()
{
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u;
    return u(e);
}

int main(int argc, char const *argv[])
{
    int count = 100;
    while (count--)
    {
        cout << genRandom() << endl;
    }
    return 0;
}
