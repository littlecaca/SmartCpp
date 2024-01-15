#include <iostream>
#include <string>
#include <sstream>

using std::istringstream;
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
    istringstream is("you are really a genius!\nif you don't believe\nI don't know how to say\n...");
    
    read(is);
    return 0;
}
