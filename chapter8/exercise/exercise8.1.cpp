#include <iostream>
#include <string>

using std::istream;
using std::cout;
using std::endl;
using std::string;
using std::cin;

istream &read(istream &is) {
    string input;
    while (getline(is, input)) {
        cout << input << endl;
    }
    if (is.eof()) {
        cout << "end of file" << endl;
    }
    is.clear();
    if (is.eof()) {
        cout << "end of file" << endl;
    }
    cout << "last:" << endl;
    if (getline(is, input))
        cout << input;

    return is;
}

int main(int argc, char const *argv[])
{
    /* code */
    read(cin);
    return 0;
}
