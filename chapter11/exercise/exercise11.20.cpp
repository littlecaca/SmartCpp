#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    // open the input file stream
    ifstream is("input.txt");
    if (!is.is_open()) {
        cout << "can not open the file" << endl;
        return -1;
    }
    string word;
    map<string, size_t> word_count;

    // count the words
    while (is >> word)
        ++word_count.insert({word, 0}).first->second;

    // outoput
    for (auto p : word_count) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
