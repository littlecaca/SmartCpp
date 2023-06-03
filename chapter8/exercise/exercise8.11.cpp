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
using std::cin;
using std::ostringstream;
using std::ofstream;

// an aggregate class
struct PersonInfo
{
    string name;
    vector<string> phone;
};

int main(int argc, char const *argv[])
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    ifstream numbers("phone_numbers.txt");

    while (getline(numbers, line)) {
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while (record >> word) {
            info.phone.push_back(word);
        }
        people.push_back(info);
        record.clear();
    }

    // write the names of people into another file
    // that is too easy, I don't want to waste time
    // ostringstream names;


    return 0;
}
