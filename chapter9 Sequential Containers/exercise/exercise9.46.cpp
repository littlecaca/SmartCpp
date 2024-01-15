#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

string toFormal(const string &raw, const string &prefix, const string &sufix) {
    string formal = raw;
    string::size_type index = 0;
    formal.insert(index, prefix);
    formal.insert(formal.size(), sufix);
    
    return formal;
}

int main(int argc, char const *argv[])
{
    cout << toFormal("Jeck", "Mr.", ".Big") << endl;
    
    return 0;
}
