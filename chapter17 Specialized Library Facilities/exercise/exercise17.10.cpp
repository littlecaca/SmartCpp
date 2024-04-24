#include <iostream>
#include <bitset>

using namespace std;

int main(int argc, char const *argv[])
{
    bitset<32> bits;
    int selected[] = {1, 2, 3, 5, 8, 13, 21};
    for (int i = 0; i < sizeof(selected) / sizeof(int); ++i)
        bits.set(selected[i]);
    cout << bits << endl;
    return 0;
}
