#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
    /*
     * Functions with No Return Value
     *
     * A function with a void return type may return the result of calling another function
     * that returns void. Returning any other expression from a void function is a compile-time
     * error.
     * 
     * Failing to provide a return after a loop that contains a return is an error. However,
     * many compilers will not detect such errors.
     * 
     * 
     * How Values Are Returned
     * 
     * It is important to keep in mind the initialization rules in functions that return local variables.
     * The copy of local variables will be returned.
     * 
     * 
     * Never Return a Reference or Pointer to a Local Object
     * 
     * 
     * Functions That Return Class Tyoes and the Call Operator
     * 
     * auto sz = shorterString(s1, s2).size()
     * 
     * 
     * Reference Returns Are Lvalues
     * 
     * Whether a function call is an lvalue depends on the return type of the function.
     * Calls to functions that return references are lvalues; other return types yield rvalues.
     */

    char &getChar(string &, string::size_type);
    string getInput(void);


    string st("you are a genius!");
    getChar(st, 2) = 'A';
    getInput() = "N";
    return 0;
}


char &getChar(string &st, string::size_type ix) {
    return st[ix];
}

string getInput() {
    string input = "no, I am not.";
    return input;
}
