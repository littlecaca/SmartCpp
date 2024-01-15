#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using std::unique_copy;
using std::cout;
using std::endl;
using std::vector;
using std::back_inserter;
using std::for_each;

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> vi{1, 2, 2, 3, 4, 4};
    vector<int> vd;

    unique_copy(vi.begin(), vi.end(), back_inserter(vd));

    for_each(vd.begin(), vd.end(), [](int i) { cout << i << " "; });
    cout << endl;
    return 0;
}
