#include "Sales_data.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


typedef struct Sales_data item;


int main(int argc, char const *argv[])
{
    item total;
    if (read(total)) {
        item trans;
        while (read(trans)) {
            if (trans.bookNo == total.bookNo) {
                combine(total, trans);
            } else {
                print(total) << endl;
                total = trans;
            }
        }
        print(total) << endl;
    } else {
        cout << "No Data?!" << endl;
        return -1;
    }
    return 0;
}
