#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::vector;


void print(const vector<string> &lines) {
    int line_no = 1;
    for (const auto &line : lines) {
        cout << line_no++ << " " << line << endl;
    }
}

void getLines(ifstream &is) {
    vector<string> lines;
    string line;
    while (getline(is, line)) {
        lines.push_back(line);
    }
    print(lines);
}

void getWords(ifstream &is) {
    vector<string> lines;
    string word;
    while (is >> word) {
        lines.push_back(word);
    }
    print(lines);
}

int main(int argc, char const *argv[])
{
    // create a stream
    ifstream is("file1.txt");
    if (is) {
        // getLines(is);
        getWords(is);
    } else {
        cout << "Can't open the file." << endl;
        return -1;
    }
    return 0;
}
