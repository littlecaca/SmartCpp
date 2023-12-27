#include <algorithm>
#include <set>
#include <sstream>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>


using namespace std;


int main(int argc, char const *argv[])
{
    // using a map

    unordered_map<string, size_t> word_count;
    istringstream is("this Is, is an is, good thing good");
    string word;


    // using a set

    unordered_set<string> exclude = {"the", "is", "a"};

    while (is >> word) {
        if (!isalnum(word.back()))
            word.pop_back();
        transform(word.begin(), word.end(), word.begin(), [](char c) { return tolower(c); });
        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    }
    
    for (const auto &w : word_count)
        cout << w.first <<  " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;


    return 0;
}