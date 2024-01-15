#include <list>
#include <deque>
#include <iostream>

using std::cout;
using std::endl;
using std::list;
using std::deque;

void cprint(const deque<int> &d) {
    for (auto i : d) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    list<int> li{1, 2, 3, 4, 5, 6, 7};
    deque<int> evens;
    deque<int> odds;

    for (auto i : li) {
        if (i % 2 == 0) odds.push_back(i);
        else evens.push_back(i);
    }

    cprint(odds);
    cprint(evens);
    return 0;
}
