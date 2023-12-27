#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    // read the file
    ifstream is("pairs.txt");
    string first;
    int second;
    vector<pair<string, int>> pairv;

    if (is.is_open()) {
        while (is >> first >> second) {
            pairv.push_back(make_pair(first, second));
            // pairv.push_back({first, second});
            // pairv.push_back(pair<string, int> (first, second));
        }
    } else {
        cout << "cannot open the file." << endl;
    }
    

    for (const auto &pa : pairv) {
        cout << pa.first << " , " << pa.second << endl;
    }

    return 0;
}
