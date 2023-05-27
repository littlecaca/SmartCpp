#include "../adt.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
    Sales_data total;
    if (read(cin, total)) {
        Sales_data sale;
        while (read(cin, sale)) {
            if (sale.bookNo == total.bookNo) {
                total.combine(sale);
            } else {
                print(cout, total);
                total = sale;
            }
        }
        print(cout, total);
    } else {
        cout << "No sales?!" << endl;
    }
    return 0;
}
