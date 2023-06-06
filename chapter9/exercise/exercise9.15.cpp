#include <vector>
#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::list;

inline bool is_equal(const vector<int> &v1, const vector<int> &v2) {
    return v1 == v2;
}

bool is_equal(const list<int> &li, const vector<int> &ve) {
    auto iter_li = li.cbegin();
    auto iter_ve = ve.cbegin();
    auto last_li = li.cend();
    auto last_ve = ve.cend();

    while (iter_li != last_li && iter_ve != last_ve) {
        if (*iter_li++ != *iter_ve++) return false;
    }

    if (iter_li == last_li && iter_ve == last_ve) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> v1{1, 2, 3, 4};
    vector<int> v2{1, 2, 3, 4};
    const char *result1 = is_equal(v1, v2) ? "yes, they are equal!" : "no, they differs!";
    cout << result1 << endl;

    list<int> l1{1, 2, 3, 4};
    const char *result2 = is_equal(l1, v2) ? "yes, they are equal!" : "no, they differs!";
    cout << result2 << endl;
    
    return 0;
}
