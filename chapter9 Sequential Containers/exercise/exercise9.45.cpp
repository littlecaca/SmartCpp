#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

string toFormal(const string &raw, const string &prefix, const string &sufix) {
    string formal = raw;
    auto iter = formal.begin();
    formal.insert(iter, prefix.begin(), prefix.end());
    formal.append(sufix);
    return formal;
}

int main(int argc, char const *argv[])
{
    cout << toFormal("Jeck", "Mr.", ".Big") << endl;
    
    return 0;
}
