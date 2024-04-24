#include <random>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

/*
 * Write a version of the word transformation program from §
 * 11.3.6 (p. 440) that allows multiple transformations for a given word and
 * randomly selects which transformation to apply.
 */

map<string, vector<string>> buildMap(ifstream &map_file)
{
    map<string, vector<string>> trans_map; // holds the transformations
    string key;                    // a word to transform
    string value;                  // phrase to use instead
    string item;
    // read the first word into key and the rest of the line into value
    while (map_file >> key && getline(map_file, value))
    {
        if (value.size() > 1)                 // check that there is a transformation
        {
            istringstream is(value);
            while (is >> item)
            trans_map[key].push_back(item); // skip leading space
        }
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

const string &
transform(const string &s, const map<string, vector<string>> &m)
{
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u;

    // the actual map work; this part is the heart of the program
    auto map_it = m.find(s);
    // if this word is in the transformation map
    if (map_it != m.cend())
        return map_it->second[u(e) % map_it->second.size()]; // use the replacement word
    else
        return s; // otherwise return the original unchanged
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file); // store the transformations
    string text;                         // hold each line from the input
    while (getline(input, text))
    {                               // read a line of input
        istringstream stream(text); // read each word
        string word;
        bool firstword = true; // controls whether a space is printed
        while (stream >> word)
        {
            if (firstword)
                firstword = false;
            else
                cout << " "; // print a space between words
            // transform returns its first argument or its transformation
            cout << transform(word, trans_map); // print the output
        }
        cout << endl; // done with this line of input
    }
}