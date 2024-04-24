#include <regex>
#include <iostream>

using namespace std;
using namespace regex_constants;

int main(int argc, char const *argv[])
{
    string phone_rule = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex phone_re(phone_rule);
    smatch mat;
    string line;
    string format = "$2-$5-$7";
    while (getline(cin, line) && line != "quit")
    {
        cout << regex_replace(line, phone_re, format, format_first_only) << endl;
    }
    return 0;
}
