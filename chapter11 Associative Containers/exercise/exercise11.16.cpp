#include <iostream>
#include <map>
#include <set>
#include <string>

using std::map;
using std::cout;
using std::endl;
using std::multiset;
using std::string;

int main(int argc, char const *argv[])
{
    map<int, int> m = {{1, 2}};
    m.begin()->second = 7;

    cout << m[1] << endl;
    cout << "Done" << endl;

    // test multiset
    multiset<int, int> ms;
    map<string, int>::iterator map_it;

    multiset<int>::const_iterator ms_it;
    return 0;
}
