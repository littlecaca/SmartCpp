#include <string>
#include <iostream>
#include <deque>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::deque;
using std::list;

int main(int argc, char const *argv[])
{
    string line;
    list<string> input;
    while (getline(cin, line)) {
        input.push_back(line);
    }

    // print lines
    for (auto iter = input.cbegin(), last = input.cend();
         iter != last; ++iter) {
        cout << *iter << endl;
    }
    

    return 0;
}
