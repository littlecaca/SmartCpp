#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::count;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::make_shared;
using std::map;
using std::ostream;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

#define DISTANCE ('a' - 'A')

string &format_word(string &w1) {
    if (std::ispunct(w1.back()))
        w1.erase(w1.end() - 1);
    for (auto &c : w1) {
        if (std::isalpha(c) && c < 'a')
            c += DISTANCE;
    }
    return w1;
}

class QueryResult {
    friend class TextQuery;

  public:
    QueryResult(string keyword, shared_ptr<vector<string>> shared_v)
        : key(keyword), sv(shared_v){};
    const string key;

    const set<int> &get_linenums() const { return linenums; }
    size_t get_count() const { return count; }
    const string &get_line(int line_no) const { return (*sv)[line_no]; }

  private:
    // The shared data containing the queried lines of text
    const shared_ptr<const vector<string>> sv;
    set<int> linenums;
    size_t count = 0;
    void set_linenum(int line_index) { linenums.emplace(line_index); }
    void set_count(int ct) { count = ct; }
};

class TextQuery {
  public:
    TextQuery(ifstream &infile) : sv(make_shared<vector<string>>()) {
        string line;
        while (getline(infile, line))
            sv->push_back(line);
    };
    shared_ptr<const QueryResult> query(string key) const {
        auto qr = make_shared<QueryResult>(key, sv);
        format_word(key);

        int total = 0;
        int line_index = 0;
        for (auto &line : *sv) {
            istringstream is(line);
            string word;
            int count = 0;
            while (is >> word) {
                if (format_word(word) == key)
                    ++count;
            }
            if (count) {
                qr->set_linenum(line_index);
                total += count;
            }
            ++line_index;
        }
        qr->set_count(total);
        return qr;
    };

  private:
    shared_ptr<vector<string>> sv;
};

ostream &print(ostream &os, shared_ptr<const QueryResult> result) {
    if (!result->get_count()) {
        os << result->key << " does not occur...";
    } else {
        os << result->key << " occurs " << result->get_count() << " times";
        auto &linenums = result->get_linenums();

        for (const auto line_no : linenums) {
            os << "\n"
               << "(line " << line_no + 1 << ")" << result->get_line(line_no);
        }
    }
    return os;
}

/*
 * When we design a class, it can be helpful to write programs using the
 * class before actually implementing the members. That way, we can see
 * whether the class has the operations we need.
 */
void runQueries(ifstream &infile) {
    TextQuery tq(infile);

    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, char const *argv[]) {
    ifstream infile("exercise/input.txt");
    if (infile.is_open())
        runQueries(infile);
    else {
        cout << "cann't open the input file" << endl;
        return -1;
    }
    return 0;
}
