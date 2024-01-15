#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    istream_iterator<int> is_iter(cin), eof;
    ostream_iterator<int> os_iter(cout, " ");
    vector<int> vi(is_iter, eof);
    sort(vi.begin(), vi.end());
    unique_copy(vi.begin(), vi.end(), os_iter);
    cout << endl;

    return 0;
}
