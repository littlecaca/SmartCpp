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
        if (regex_search(line, mat, phone_re))
        {
            cout << mat.format(format) << endl;
        }
    }
    return 0;
}
