#include <regex>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;


// members are public by default; see § 7.2 (p. 268)
struct PersonInfo {
 string name; vector<string> phones;
};

string format(const string &nums)
{
    return nums;
}


class PhoneValide
{
public:
    PhoneValide()
    {
        phone_num_rule.assign("^(\\()?(\\+86)?(\\))?([_\\-\\s])?(\\d[_\\-\\s])?1\\d{10}$");
    }
    bool valid(const string &) const;
private:
    regex phone_num_rule;
    bool valid_smatch(const smatch &) const;
};

bool PhoneValide::valid_smatch(const smatch &match) const
{
    if (match[1].matched ^ match[3].matched)
        return false;
    if (match[1].matched && !match[2].matched)
        return false;
    if (match[2].matched && (match[1].matched ^ !match[4].matched))
        return false;
    if (!match[2].matched && match[4].matched)
        return false;
    

    return true;
}

bool PhoneValide::valid(const string &nums) const
{
    smatch results;
    if (regex_match(nums, results, phone_num_rule))
    {
        if (valid_smatch(results))
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<PersonInfo> people; // will hold all the records from the input
    string line, word;
    // read the input a line at a time until cin hits end-of-file (or another error)
    while (getline(cin, line)) {
        PersonInfo info; // create an object to hold this record's data
        istringstream record(line); // bind record to the line we just read
        record >> info.name; // read the name
        while (record >> word) // read the phone numbers
        info.phones.push_back(word); // and store them
        people.push_back(info); // append this record to people
    }
    PhoneValide verfier;
    for (const auto &entry : people) { // for each entry in people
        ostringstream formatted, badNums; // objects created on each loop
        for (const auto &nums : entry.phones) { // for each number
            if (!verfier.valid(nums)) {
                badNums << " " << nums; // string in badNums
            } else {
                // ''writes'' to formatted's string
                formatted << " " << format(nums); 
            }
            if (badNums.str().empty()) // there were no bad numbers
                cout << entry.name << " " // print the name
                << formatted.str() << endl; // and reformatted numbers
            else // otherwise, print the name and bad numbers
                cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() <<
                endl;
        }
    }
    return 0;
}

