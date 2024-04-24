#include <regex>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    regex r1("\\w*[^c]ei\\w*");
    string raw = "receipt Freind theif receive";
    for (sregex_iterator it(raw.begin(), raw.end(), r1), end; it != end; ++it)
    {
        cout << it->str() << "\t";
    }
    cout << endl;
    return 0;
}
