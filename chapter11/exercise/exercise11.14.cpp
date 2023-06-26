#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    // define a vecotor storing a pair type
    vector<pair<string, size_t>> children;
    
    // define hte map
    map<string, vector<string>> families;

    // add new families
    families["Smith"] = {"Anny", "Tom"};
    families["Elon"] = {"Musk", "Howardd"};

    // add new children to an exising family
    families["Elon"].push_back("Maria");
    families["Smith"].push_back("Lily");

    for (const auto &f : families) {
        cout << f.first << " : ";
        for (const auto &c : f.second) {
            cout << c << " ";
        } 
        cout << endl;
    }
    
    return 0;
}
