#include <sstream>
#include <iostream>
#include <string>

using std::stringstream;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::cin;
using std::cout;
using std::endl;


int main(int argc, char const *argv[])
{
    /* code */
    stringstream strm;
    
    string s1 = "you are a genius";
    stringstream strm2(s1);

    const string &rs1 = strm2.str();
    strm.str("you are an idiot");
    
    // output 
    string line;
    while (getline(strm, line)) {
        cout << line << endl;
    }
    return 0;
}
