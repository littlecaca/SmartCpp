#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::bind;
using std::ref;
using namespace std::placeholders;
using std::vector;
using std::find_if;
using std::string;

inline bool check_size(int i, const string &s) {
    return i < 0 ? false : static_cast<string::size_type>(i) > s.size();
}

int main(int argc, char const *argv[])
{
    vector<int> vi{1, 2, 6, 7, 8};
    
    auto target = find_if(vi.begin(), vi.end(), bind(check_size, _1, "you"));

    cout << *target << endl;
    return 0;
}


