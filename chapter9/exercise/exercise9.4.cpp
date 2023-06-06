#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

// if can't find the key, then return it.end()
vector<int>::iterator find(vector<int>::iterator first, const vector<int>::iterator last, int key) {
    while (first != last) {
        if (*first++ == key) return first;
    }
    return last;
}

int main(int argc, char const *argv[])
{
    vector<int> vi{1, 3, 5, 546, 435, 456, 23, 35, 56};
    if (find(vi.begin(), vi.end(), 5) != vi.end()) cout << "yes, find it!" << endl;
    
    
    return 0;
}
