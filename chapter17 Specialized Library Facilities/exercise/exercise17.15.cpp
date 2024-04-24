#include <regex>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    regex r1("\\w*[^c]ei\\w*");
    string raw;
    while (cin >> raw && raw != "quit")
    {  
        if (regex_search(raw, r1))
            cout << "no violate the rule";
        else cout << "do violate the rule";
        cout << endl;
    }
    return 0;
}
