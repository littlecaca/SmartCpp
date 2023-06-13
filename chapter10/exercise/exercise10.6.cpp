#include <algorithm>
#include <vector>
#include <iostream>

using std::fill_n;
using std::vector;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    vector<int> vi {1, 2, 3, 5};
    fill_n(vi.begin(), vi.size(), 100);

    for (auto i : vi) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
