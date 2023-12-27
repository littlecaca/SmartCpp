#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <vector>

#define DISTANCE ('a' - 'A')

using namespace std;

// Convert the word to a universal format
string &format_word(string &w1) {
    if (std::ispunct(w1.back()))
        w1.erase(w1.end() - 1);
    for (auto &c : w1) {
        if (std::isalpha(c) && c < 'a')
            c += DISTANCE;
    }
    return w1;
}

// Read lines into a vector
shared_ptr<vector<string>> load_file(ifstream &infile) {
    auto sv = make_shared<vector<string>>();
    string line;
    while (getline(infile, line)) {
        sv->push_back(line);
    }
    return sv;
}

// Query the given keyword
shared_ptr<const set<size_t>> query(shared_ptr<const vector<string>> sv,
                                    string key, size_t &cnt) {
    format_word(key);
    auto linenums = make_shared<set<size_t>>();
    size_t count = 0;
    size_t line_no = 0;
    for (const auto &line : *sv) {
        istringstream is(line);
        string word;
        size_t local_count = 0;
        while (is >> word) {
            if (format_word(word) == key) {
                ++local_count;
            }
        }
        if (local_count) {
            linenums->emplace(line_no);
            count += local_count;
        }
        ++line_no;
    }
    cnt = count;
    return linenums;
}

// Print the result
ostream &print(ostream &os, string key, size_t count,
               shared_ptr<const set<size_t>> linenums,
               shared_ptr<const vector<string>> sv) {
    if (!count) {
        cout << key << " does not occur...";
    } else {
        cout << key << " occurs " << count << " times";
        for (auto line_no : *linenums) {
            cout << "\n"
                 << "(line " << line_no + 1 << ")" << (*sv)[line_no];
        }
    }
    return os;
}

// Run queries
void run_queries(ifstream &infile) {
    string cmd;
    auto sv = load_file(infile);

    while (true) {
        cout << "enter a word to look for, or q to quit: ";
        if (!(cin >> cmd) || cmd == "q")
            break;
        size_t count;
        auto linenums = query(sv, cmd, count);
        print(cout, cmd, count, linenums, sv) << endl;
    }
}

int main(int argc, char const *argv[]) {
    ifstream infile("input.txt");
    if (infile.is_open()) {
        run_queries(infile);
    } else {
        cout << "can not open the input file" << endl;
        return -1;
    }
    return 0;
}
