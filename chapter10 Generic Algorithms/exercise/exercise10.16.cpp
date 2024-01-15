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

inline string make_plural(const string &s) {
    return s + "s";
}

int main(int argc, char const *argv[])
{
    /* code */
    // remove the duplicates
    vector<string> ls{"you", "are", "really", "a", "genius", "!"};
    elimDups(ls);
    string::size_type sz = 5;

    // sort by size
    sort(ls.begin(), ls.end(), [](const string &s1, const string &s2)
         { return s1.size() < s2.size(); });

    // find the elements whose size are bigger than sz
    auto edge = find_if(ls.cbegin(), ls.cend(), [sz] (const string &s)
                        { return s.size() >= sz; });
    
    int count = 0;
    for_each(edge, ls.cend(), [&count](const string &) { ++count; });
    
    cout << count << " " << make_plural("word") << " of length "
         << sz << " or longer" << endl;
        
    for_each(edge, ls.cend(), [](const string &s) { cout << s << endl; });
    return 0;
}
