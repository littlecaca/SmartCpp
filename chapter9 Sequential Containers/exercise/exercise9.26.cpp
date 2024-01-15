#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::end;
using std::begin;

#define PRINT(container) \
    for (auto e : container) \
        cout << e << " "; \
    cout << endl;


int main(int argc, char const *argv[])
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vi(begin(ia), end(ia));
    list<int> li(vi.begin(), vi.end());

    // erase the odd elements from list
    for (auto iter = li.begin(), last = li.end();
         iter != last;) {
            if (*iter % 2 != 0) {
                iter = li.erase(iter);
            } else {
                ++iter;
            }
    }

    // erase the even elements from vector
    for (auto iter = vi.begin();
         iter != vi.end();) {
            if (*iter % 2 == 0) {
                iter = vi.erase(iter);
            } else {
                ++iter;
            }
    }

    // print
    PRINT(li);
    PRINT(vi);
    return 0;
}
