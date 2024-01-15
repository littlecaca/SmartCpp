#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::list;
using std::for_each;
using std::unique;
using std::sort;
using std::vector;


void elimDups(vector<string> &ls) {
    // sort the elimDups
    sort(ls.begin(), ls.end());

    // remove the concequtive duplicates
    auto edge = unique(ls.begin(), ls.end());

    // remove
    ls.erase(edge, ls.end());
}

void elimDups(list<string> &ls) {
    ls.sort();

    ls.unique();
}


int main(int argc, char const *argv[])
{
    /* code */
    list<string> ls{"you", "you", "are", "really", "really", "cool", "!"};
    elimDups(ls);
    for_each(ls.begin(), ls.end(), [](const string &s)
             { cout << s << " "; });
    cout << endl;
    return 0;
}
