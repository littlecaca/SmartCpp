#include <iostream>
#include <stdexcept>

using std::runtime_error;
using std::overflow_error;
using std::cout;
using std::cin;
using std::endl;

double divid(const int i1, const int i2) {
    if (i2 == 0)
        throw runtime_error("The divisor can not be zero");
    return static_cast<double>(i1) / i2;
}

int main(int argc, char const *argv[])
{
    int i1, i2;
    try {
        if (cin >> i1 >> i2) {
            while (true) {
                try {
                    cout << divid(i1, i2) << endl;
                } catch (runtime_error const &err_run) {
                    cout << err_run.what() << endl
                        << "Input a new divisor? Enter y or n" << endl;
                    char c;
                    if (cin >> c && c != 'n') {
                        cin >> i2;
                        continue;  
                    }
                }
                break;
            }
        }
    } catch (overflow_error const &err_over) {
        cout << err_over.what() << endl;
    }
    
    return 0;
}
