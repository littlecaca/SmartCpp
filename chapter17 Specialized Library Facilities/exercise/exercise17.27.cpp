#include <regex>
#include <iostream>

using namespace std;
using namespace regex_constants;

int main(int argc, char const *argv[])
{
    string match_rule = "(\\d{5})(\\d{4})";
    regex match_re(match_rule);
    smatch res;
    string line;
    string format = "$1-$2";
    while (getline(cin, line) && line != "quit")
    {
        cout << regex_replace(line, match_re, format) << endl;
    }
    return 0;
}
