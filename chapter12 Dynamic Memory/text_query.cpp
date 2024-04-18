#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include "text_query.h"

string &format_word(string &w1) {
    if (std::ispunct(w1.back()))
        w1.erase(w1.end() - 1);
    for (auto &c : w1) {
        if (std::isalpha(c) && c < 'a')
            c += DISTANCE;
    }
    return w1;
}

string make_plural(size_t count, const string &word, const string &suffix) {
    if (count > 1) {
        return word + suffix;
    }
    return word;
}


TextQuery::TextQuery(ifstream &infile) : file(new vector<string>) {
    string text;
    while (getline(infile, text)) {
        file->push_back(text);
        int n = file->size() - 1; // n is the current line_no
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm[format_word(word)];
            if (!lines) // the default initialization of shared_ptr will make it
                        // null
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &key) const {
    // Format the key word
    string sought = key;
    format_word(sought);

    static shared_ptr<set<line_no>> nodata(new set<line_no>);

    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num)
           << endl;
    return os;
}

void run_queries(ifstream &infile) {
	TextQuery tq(infile);
	while (true) {
		cout << "enter a word to check for, or enter q to exit: ";
		string cmd;
		if (!(cin >> cmd) || cmd ==  "q")
			break;
		print(cout, tq.query(cmd)) << endl;
	}
}

int main(int argc, char const *argv[])
{
	// ifstream infile("exercise/input.txt");
	// if (!infile.is_open()) 
	// 	cout << "can not open the input file" << endl;
	// run_queries(infile);

    ifstream infile("exercise/input.txt");
	TextQuery tq(infile);
    TextQuery tq2(tq);
    tq2 = tq;

    print(cout, tq.query("found")) << endl;
    print(cout, tq2.query("found")) << endl;
    
	return 0;
}
