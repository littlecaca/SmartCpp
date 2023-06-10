#include <forward_list>
#include <iostream>

using std::cout;
using std::endl;
using std::forward_list;

int main(int argc, char const *argv[])
{
    forward_list<int> fi{1, 2, 3, 4, 5, 6, 7};

    // delete the odd-valued elements
    auto prev = fi.before_begin(), curr = fi.begin();
    while (curr != fi.end()) {
        if (*curr % 2) {
            curr = fi.erase_after(prev);
        } else {
            prev = curr;
            ++curr;
        }
    }

    for (auto e : fi) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
