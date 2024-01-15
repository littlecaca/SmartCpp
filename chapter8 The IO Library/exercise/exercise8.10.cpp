#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    // store each line from a file to vector
    vector<string> vs;
    ifstream ifs("file1.txt");
    string line;
    while (getline(ifs, line)) {
        vs.push_back(line);
    }
    // read each word from vector using istringstream
    string word;
    istringstream iss;

    for (const auto &line : vs) {
        iss.str(line);
        while (iss >> word) {
            cout << word << "_";
        }
        cout << endl;
        // don't forget to clear the failbit and eofbit
        iss.clear();
    }
    return 0;
}
