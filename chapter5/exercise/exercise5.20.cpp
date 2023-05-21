#include <cctype>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::isalpha;
using std::islower;
using std::string;

int main(int argc, char const *argv[]) {
    string word, last;
    bool flag = true;

    while (cin >> word) {
        if (islower(word[0])) {
            last = word;
            continue;
        }

        if (!isalpha(word[word.size() - 1])) {
            word.pop_back();
        }

        if (word == last) {
            flag = false;
            cout << word << endl;
            break;
        }
        last = word;
    }

    if (flag) {
        cout << "There is no word starting with uppercase letter was repeated."
        << endl;
    }

    return 0;
}