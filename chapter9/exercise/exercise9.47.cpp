#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

void filter1(const string &raw, const string &key1, const string &key2 = "") {
    string::size_type pos = 0;

    while ((pos = raw.find_first_of(key1, pos)) != string::npos) {
        cout << raw[pos] << " ";
        ++pos;
    }
    cout << endl;

    if (!key2.empty()) {
        pos = 0;
        while ((pos = raw.find_first_of(key2, pos)) != string::npos) {
            cout << raw[pos] << " ";
            ++pos;
        }
        cout << endl;
    }
}


void filter2(const string &raw, const string &key1, const string &key2 = "") {
    string::size_type pos = 0;
    string::size_type curr = 0;

    while ((pos = raw.find_first_not_of(key1, pos)) != string::npos) {
        while (curr < pos) cout << raw[curr++] << " ";
        ++pos;
    }
    cout << endl;

    if (!key2.empty()) {
        pos = 0;
        curr = 0;
        while ((pos = raw.find_first_of(key2, pos)) != string::npos) {
            while (curr < pos) cout << raw[curr++] << " ";
            ++pos;
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    string raw("ab2c3d7R4E6");
    string key1, key2;
    for (char c = '0'; c <= '9'; ++c) {
        key1 += c;
    }
    
    for (char c = 'a'; c <= 'z'; ++c) {
        key2 += c;
        key2 += toupper(c);
    }
    filter1(raw, key1, key2);
    filter2(raw, key1, key2);
    return 0;
}
