#include <vector>
#include <numeric>
#include <iostream>

using std::vector;
using std::accumulate;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    vector<int> vi{1, 2, 3, 4, 5};
    int sum = accumulate(vi.cbegin(), vi.cend(), 0);
    cout << "The sum is " << sum << endl;
    return 0;
}
