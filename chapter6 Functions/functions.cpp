#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
 * A function call does two things: initialize the function's parameters from the 
 * corresponding arguments, and transfer control to that function.
 * 
 * 
 * Parameters and Arguments
 * 
 * Arguments(实参) are the initializers for a function's parameters(形参), we have no guarantees about
 * the order in which arguments are evaluated.
 * 
 * 
 * Function Return Type
 * 
 * Most types can be used as the return type of function. However, the return type may
 * not be an array type, ot a function type.
 * 
 * In C++, we can define several different functions that have the same name. However, we can do that
 * only if their parameter lists are sufficiently different.
 * 
 * 
 * Pointer or Reference Parameters and `const`
 * 
 * Like general initialization rules, we can initialize an object with a low-level `const` from a non`const`
 * object but not vise versa, and a plain reference must be initialized from an object of the same type.
 */

string &getInput() {
    static string you;
    cin >> you;
    return you;
}

int getNum() {
    return 3;
}

int getNum(int n) {
    return n + 3;
}

// error: redefinition of ‘int getNum(int)’
// int getNum(const int n) {
//     return n + 3;
// }

// using a reference instead of a reference to const unduly limits the types 
// of argument that can be used with the function

// bad design: the st should be reference to const string
void out_string(string &st) {
    cout << st << endl;
}

// error
// void wrong_case() {
//     out_string("hello");
// }


// array parameters
// the compiler will check only that the argument has type const int *
void print(const int *);
void print(const int[]);
void print(const int[10]);

void print(const int *n) {
    ;
}



int main(int argc, char const *argv[])
{
    int (*f)() = &getNum;

    cout << f() << " " << (*f)() << endl;
    
    return 0;
}
