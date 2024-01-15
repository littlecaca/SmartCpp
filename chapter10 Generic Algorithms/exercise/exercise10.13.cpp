#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::partition;


inline bool hasMoreThanFive(const string &word) {
    return word.size() > 5;
}

int main(int argc, char const *argv[])
{
    vector<string> vs{"you", "are", "really", "a", "genius"};
    
    auto iter = partition(vs.begin(), vs.end(), hasMoreThanFive);

    for (auto last = vs.end(); iter != last; ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    
    return 0;
}
