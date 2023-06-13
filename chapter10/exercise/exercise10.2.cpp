#include <algorithm>
#include <list>
#include <string>
#include <iostream>

using std::count;
using std::list;
using std::string;
using std::endl;
using std::cout;
using std::cin;

int main(int argc, char const *argv[])
{
    string word;
    string given = "tired";
    list<string> ls;

    while (cin >> word) {
        ls.push_back(word);
    }

    cout << "There are " << count(ls.cbegin(), ls.cend(), given)
         << " ints with value " << given << endl;

    return 0;
}
