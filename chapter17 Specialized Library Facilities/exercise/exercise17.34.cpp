#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    // The skipws does not skip null character
    stringstream oss;
    oss << "lalala~" << ends << "yyyy~";
    string word;
    while (oss >> word)
    {
        cout << word << endl;
     }
    return 0;
}
