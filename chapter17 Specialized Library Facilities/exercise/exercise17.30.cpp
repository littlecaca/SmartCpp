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

unsigned int genRandom(unsigned min, unsigned max)
{
    unifom_dis = uniform_int_distribution<unsigned>(min, max);
    return genRandom();
}

int main(int argc, char const *argv[])
{
    int count = 100;
    while (count--)
    {
        cout << genRandom(12, 28) << endl;
    }
    return 0;
}
