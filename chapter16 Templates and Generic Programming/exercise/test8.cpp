#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> foo{1, 2, 3, 4, 5, 6, 7, 8};

    vector<int>::iterator it = find(foo.begin(), foo.end(), 4);
    vector<int>::iterator it2 = find(foo.begin(), foo.end(), 2);
    vector<int>::iterator it3 = find(foo.begin(), foo.end(), 6);

    --it;
    foo.erase(it);
        
    cout << *it << endl;
    return 0;
}
