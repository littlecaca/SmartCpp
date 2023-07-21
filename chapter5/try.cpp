#include <iostream>
#include <string>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::runtime_error;
using std::logic_error;

bool addItem(string &item1, string &item2) {
    if (item1 != item2)
        throw runtime_error("Data must refer to same ISBN");
    return true;
}


int main(int argc, char const *argv[])
{
    /*
     * Exceptions are run-time anomalies
     *
     * A program that contains code that might raise an exception (usually) has another
     * part to handle whatever happened.  
     * 
     * The search for a handler reverses the call chain. If no appropriate catch is found,
     * execution is transferred to a library function named `terminate`.
     * 
     * 
     * Caution: Writing Exception Safe Code Is Hard
     * 
     * At the point where the exception occurs, some of the computations that the caller requested
     * may have been done, while others remain undone. In general, bypassing part of the program 
     * might mean that an object is left in an invalid or incomplete state, or that a resource is not
     * free, and so on.
     * 
     * Programs that properly "clean up" during exception handling are said to be exception safe. Writing
     * exception safe code is surprisingly hard, and (largely) beyond the scope of this laguage Primer.;)
     */

    string item1, item2;
    cout << "Please input two word: ";
    while (cin >> item1 >> item2) {
        try {
            if (addItem(item1, item2))
                cout << "success" << endl;
        } catch (runtime_error err) {
            // Each of the library exception classes defines a member function named what
            cout << err.what()
                 << "\nTry Again? Enter y or n" << endl;
            char c;
            if (!(cin >> c) || c == 'n')
                break;
        }
        cout << "Please input two word: ";
    }
    
    return 0;
}
