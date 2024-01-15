#include <string>
#include <iostream>
#include <cctype>

using std::cout;
using std::endl;
using std::string;


void replace(string &s, const string &oldVal, const string &newVal) {
    string word;
    auto iter = s.begin();

    while (iter != s.end()) {
        if (isalnum(*iter)) {
            word += *iter;
        } else {
            if (!word.empty()) {
                if (word == oldVal) {
                    // cout << "yes" << endl;
                    iter = s.erase(iter - oldVal.size(), iter);
                    iter = s.insert(iter, newVal.begin(), newVal.end());
                    iter += newVal.size();
                }
                word.clear();
            }
        }
        ++iter;
    }
}

int main(int argc, char const *argv[])
{
    string s = "but, we can't do this, my lord!! my lord!! this is horrible!!";
    cout << s << endl;
    replace(s, "this", "that thing");
    cout << s << endl;
    return 0;
}
