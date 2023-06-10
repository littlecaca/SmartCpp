#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    vector<char> vc{'y', 'o', 'u'};
    
    string s;
    s.reserve(100);
    s.assign(vc.begin(), vc.end());
    cout << s << endl;
    return 0;
}
