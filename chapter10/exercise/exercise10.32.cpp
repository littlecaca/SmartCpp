#include "../../chapter7/access_specifiers.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <functional>

using namespace std;
using namespace std::placeholders;


inline bool compareIsbn(const Sales_data &s1, const Sales_data &s2) {
    return s1.isbn() == s2.isbn();
}


int main(int argc, char const *argv[])
{
    // read the transactions
    ifstream is("../../chapter7/exercise/transactions.txt");
    vector<Sales_data> vtrans;
    Sales_data sale;
    if (is) {
        while (read(is, sale)) {
            vtrans.push_back(sale);
        }
    } else {
        cout << "can not open the transactions file" << endl;
        return -1;
    }

    // process the sale data
    sort(vtrans.begin(), vtrans.end(), [](const Sales_data &s1,
         const Sales_data &s2) { return s1.isbn() < s2.isbn(); });
    

    
    for (auto iter = vtrans.begin(), last = vtrans.end();
         iter != last; ) {
        auto edge = find_if_not(iter, last, bind(compareIsbn, _1, *iter));
        auto sum = accumulate(++iter, edge, *iter, [](Sales_data &s1, const Sales_data &s2)
                    { return s1.combine(s2); });
        print(cout, sum) << endl;
        iter = edge;
    }

    cout << string(30, '-') << endl;

    for_each(vtrans.begin(), vtrans.end(), bind(print, ref(cout), _1, "\n"));
    
    return 0;
}

