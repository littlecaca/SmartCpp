#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
    vector<int> vi;
    // auto i1 = vi.front();   // segmentation fault
    // auto i2 = vi[0];        // segmentation fault
    // auto i3 = *vi.begin();  // segmentation fault
    // auto i4 = vi.at(0);     // throw an exception

    return 0;
}
