#include <string>
#include <iostream>
#include <cctype>

using std::cout;
using std::endl;
using std::string;


void replace(string &s, const string &oldVal, const string &newVal) {
    string word;
    string::size_type index = 0;

    while (index != s.size()) {
        if (isalnum(s[index])) {
            word += s[index];
        } else {
            if (!word.empty()) {
                if (word == oldVal) {
                    // cout << "yes" << endl;
                    s.replace(index - oldVal.size(), oldVal.size(), newVal);
                    index = index - oldVal.size() + newVal.size();
                }
                word.clear();
            }
        }
        ++index;
    }
}

int main(int argc, char const *argv[])
{
    string s = "but, we can't do this, my lord!! my lord!!";
    cout << s << endl;
    replace(s, "lord", "commander");
    cout << s << endl;
    return 0;
}
