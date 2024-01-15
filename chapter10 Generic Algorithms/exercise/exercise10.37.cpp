#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto begin = vi.crend() - 7, end = vi.crend() - 2;
    list<int> li(begin, end); 
    for (auto i : li) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
