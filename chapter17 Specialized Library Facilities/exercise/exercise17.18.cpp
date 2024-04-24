#include <algorithm>
#include <vector>
#include <string>
#include <regex>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    regex r1("\\w*[^c]ei\\w*");
    string raw = "receipt Freind theif receive albeit";

    vector<string> exclude{"albeit", "neighbor"};
    for (sregex_iterator it(raw.begin(), raw.end(), r1), end; it != end
        && find(exclude.begin(), exclude.end(), it->str()) == exclude.end(); ++it)
    {
        cout << it->str() << "\t";
    }
    cout << endl;
    return 0;
}
