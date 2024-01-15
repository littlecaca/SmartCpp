#include <forward_list>
#include <string>
#include <iostream>

using std::forward_list;
using std::string;
using std::cout;
using std::endl;

void insert(forward_list<string> &fs, const string &key, const string &value) {
    auto prev = fs.before_begin(), curr = fs.begin(), last = fs.end();
    while (curr != last) {
        if (*curr == key) {
            fs.insert_after(curr, value);
            break;
        }
        prev = curr;
        ++prev;
    }
    if (curr == last) {
        fs.insert_after(prev, value);
    }
}

int main(int argc, char const *argv[])
{
    forward_list<string> fs{"you", "are", "smart"};
    string key = "are";
    string value = "very";
    insert(fs, key, value);
    insert(fs, "ok", "!");

    for (auto &word : fs) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
