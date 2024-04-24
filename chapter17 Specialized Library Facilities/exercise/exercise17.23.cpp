#include <string>
#include <regex>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    regex zip_regex("\\d{5}(-?\\d{4})?");

    string raw;
    smatch result;
    while (getline(cin, raw) && raw != "quit")
    {
        if (regex_search(raw, result, zip_regex))
        {
            cout << "yes: " << result.str() << endl;
        }
        else cout << "no" << endl;
    }

    return 0;
}
