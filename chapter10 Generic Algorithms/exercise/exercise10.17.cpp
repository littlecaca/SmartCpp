#include "../../chapter7/adt.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

using std::ifstream;
using std::cout;
using std::endl;
using std::sort;
using std::vector;
using std::string;

inline bool isSmaller(const Sales_data &s1, const Sales_data &s2) {
    return s1.isbn() < s2.isbn();
}

int main(int argc, char const *argv[])
{
    vector<Sales_data> vs;
    Sales_data sale;
    ifstream is("../../chapter7/exercise/transactions.txt");

    if (is.is_open()) {
        while (read(is, sale)) {
            vs.push_back(sale);
        }
    } else {
        cout << "can not open." << endl;
        return -1;
    }

    for (auto &sale : vs) {
        print(cout, sale) << endl;
    }
    sort(vs.begin(), vs.end(), [](const Sales_data &s1, const Sales_data &s2)
         { return s1.isbn() < s2.isbn(); });

    cout << string('-', 20) << endl;

    for (auto &sale : vs) {
        print(cout, sale) << endl;
    }
    return 0;
}
