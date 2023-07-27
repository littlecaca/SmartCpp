#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <map>
#include <unordered_map>
#include <sstream>

using namespace std;


// a word transformation map
string transform(const string &rule_file, const string &transformed_file) {
    unordered_map<string, string> rules;
    ifstream rule_s(rule_file), raw_s(transformed_file);
    ostringstream transformed;

    // read the rules into a map
    string word, line;
    while (getline(rule_s, line)) {
        size_t edge = line.find_first_of(' ');
        if (edge >= line.size() - 1 || edge == 0)
            throw runtime_error("no rule for " + line);
        rules[line.substr(0, edge)] = line.substr(edge + 1);
    }

    // transform
    istringstream buffer;
    while (getline(raw_s, line)) {
        
        buffer.str(line);
        while (buffer >> word) {
            decltype(rules.begin()) it;
            if ((it = rules.find(word)) != rules.end())
                transformed << it->second;
            else
                transformed << word;

            if (!buffer.eof())
                transformed << " ";
        }
        // reset the buffer
        buffer.clear();
        if (!raw_s.eof())
            transformed << "\n";
    }

    return transformed.str();
}