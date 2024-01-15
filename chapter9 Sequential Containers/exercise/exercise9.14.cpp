#include <vector>
#include <string>
#include <list>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::list;

int main(int argc, char const *argv[])
{
    list<const char *> ls{"you", "are", "an", "genius"};
    vector<string> vs;
    vs.assign(ls.begin(), ls.end());

    for (auto &s : vs) {
        cout << s << endl;
    }
    return 0;
}
