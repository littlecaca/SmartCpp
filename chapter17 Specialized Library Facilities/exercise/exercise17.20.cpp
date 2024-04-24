#include <regex>
#include <iostream>

using namespace std;

bool valid(const smatch &match)
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

int main(int argc, char const *argv[])
{
    /*
     * Submatch     expression      rules
     *  1           (\\()?           !(1 ^ 3)
     *  2           (\\+86)?         1 -> 2
     *  3           (\\))?           
     *  4           ([_\\- ])?       !(1 ^ !4)
     */
    regex phone_num_rule("^(\\()?(\\+86)?(\\))?([_\\-\\s])?\\s*(\\d[_\\-\\s])?\\s*1\\d{10}$");
    string user_input;
    smatch results;
    while (getline(cin, user_input) && user_input != "quit")
    {
        if (regex_match(user_input, results, phone_num_rule))
        {
            if (valid(results))
                cout << "valid:";
            else cout << "invalid:";
            cout << results.str() << endl;
        }   
    }
    
    return 0;
}
