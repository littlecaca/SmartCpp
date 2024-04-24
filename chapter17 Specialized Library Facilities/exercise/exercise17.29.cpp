#include <random>
#include <iostream>

using namespace std;

static default_random_engine default_ran_e;
static uniform_int_distribution<unsigned> unifom_dis;

unsigned int genRandom()
{
    return unifom_dis(default_ran_e);
}

unsigned int genRandom(unsigned seed)
{
    default_ran_e.seed(seed);
    return genRandom();
}

int main(int argc, char const *argv[])
{
    int count = 100;
    while (count--)
    {
        cout << genRandom(count) << endl;
    }
    return 0;
}
