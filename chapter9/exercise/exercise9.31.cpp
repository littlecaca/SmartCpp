#include <list>
#include <forward_list>
#include <iostream>

using std::list;
using std::forward_list;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    list<int> li{1, 2, 3, 4, 5, 6, 7};
    forward_list<int> fi(li.begin(), li.end());

    
    auto iter = li.begin();
    while (iter != li.end()) {
        if (*iter % 2) {
            iter = li.insert(iter, *iter++);
            ++iter;
        } else {
            iter = li.erase(iter);
        }
    }

    for (auto e : li) {
        cout << e << " ";
    }
    cout << endl;
    
    return 0;
}
