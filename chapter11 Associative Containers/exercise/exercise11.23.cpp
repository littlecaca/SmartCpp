#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    // define the map
    multimap<string, vector<string>> families;

    // add new families
    families.insert({"Smith", {"Anny", "Tom"}});
    families.insert({"Elon", {"Musk", "Howardd"}});

    // add new children to an exising family

    for (const auto &f : families) {
        cout << f.first << " : ";
        for (const auto &c : f.second) {
            cout << c << " ";
        } 
        cout << endl;
    }
    cout << "Done" << endl;
    
    return 0;
}
