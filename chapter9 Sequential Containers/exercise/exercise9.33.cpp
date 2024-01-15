#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    vector<int> v{1, 2, 3, 4, 5, 6};
    
    auto begin = v.begin();
    // while (begin != v.end()) {
        // ++begin;
    cout << *begin << endl;
    v.insert(begin, 42);
        // ++begin;
        // v.insert(begin, 42);
    cout << *begin << endl;
    // }
    cout << v.capacity() << endl;
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
