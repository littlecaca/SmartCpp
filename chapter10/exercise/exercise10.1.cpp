#include <algorithm>
#include <vector>
#include <iostream>

using std::count;
using std::vector;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char const *argv[])
{
    int num;
    int given = 20;
    vector<int> vi;
    
    while (cin >> num) {
        vi.push_back(num);
    }

    cout << "There are " << count(vi.cbegin(), vi.cend(), given)
         << " ints with value " << given << endl;

    return 0;
}
