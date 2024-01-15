#include "../adt.h"
#include <iostream>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
    Sales_data total;

    // get output file name
    char const *outfile;
    if (argc > 1) {
        outfile = argv[1];
    }
    else {
        // default outfile
        outfile = "records.txt";
    }

    // create the input stream and output stream
    ifstream is("transactions.txt");
    if (is.fail()) {
        cout << "Can't open the input file." << endl;
        return -1;
    }

    ofstream records(outfile, ofstream::app);
    if (records.fail()) {
        cout << "Can't open the output file." << endl;
        return -1;
    }

    // read and write
    if (read(is, total)) {
        Sales_data sale;
        while (read(is, sale)) {
            if (sale.bookNo == total.bookNo) {
                total.combine(sale);
            } else {
                print(records, total) << endl;
                total = sale;
            }
        }
        print(records, total) << endl;
    } else {
        cout << "No sales?!" << endl;
    }

    is.close();
    records.close();
    return 0;
}
