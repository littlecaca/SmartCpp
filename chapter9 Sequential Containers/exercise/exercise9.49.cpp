#include <fstream>
#include <iostream>
#include <string>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
    ifstream ifile("text");
    string word;
    string key("acemnorsuvwxz");
    while (ifile >> word) {
        if (word.find_first_not_of(key) == string::npos)
            cout << word << endl;
    }
    return 0;
}
