#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    ifstream is("text");
    vector<string> vs;
    // adaptor
    istream_iterator<string> is_iter(is), eof;
    ostream_iterator<string> os_iter(cout, " ");

    if (is) {
        vs.assign(is_iter, eof);
    }

    copy(vs.begin(), vs.end(), os_iter);
    os_iter = "\n";

    return 0;
}
