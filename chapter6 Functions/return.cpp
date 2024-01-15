#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
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
     * 
     * 
     * List initializing the Return Value
     * 
     * 
     * In a function that returns a built-in type, a braced list may contain at most one value,
     * and that value must not require a narrowing conversion. If the function returns a class
     * typem, then the class itself defines how the initailizers are used.
     * 
     * 
     * Return from Main
     * 
     * The `main` function is allowed to terminate without a return. If control reaches the end of
     * main and there is no return, then the compiler implicitly inserts a return of 0. To make return
     * values machine independent, the cstdlib headerr defines two preprocessor variables: EXIT_FAILURE,
     * and EXIT_SUCCESS.
     * 
     * 
     * Returning a Pointer to an Array
     * 
     * 
     * Using a Trailing Return Type
     * 
     * Trailing returns can be defined for any function,  but are most useful for functions with
     * complicated return types, such as pointers(or references) to array.
     * 
     * 
     * Using decltype
     * 
     * If we know the array(s) to which our function can return a pointer, we can use decltype to 
     * declare the return type. 
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
    int n{1};
    string input = "no, I am not.";
    return input;
}

// list initializing the Return Value
vector<string> process() {
    return {"you", "are", "a"};
}

int getNum(void) {
    return {2};
}

// recursive function
int fact(int num) {
    if (num <= 1) return num;
    return num * fact(num-1);
}

// return reference to array
int (&getArrayReference())[5] {
    static int num[5] = {};
    return num;
}

// return pointer to array
int (*getArrayPointer())[5] {
    static int num[5] = {};
    return &num;
}

// intimidating? we can use type alias!
typedef int arrT[10];
using arrT = int[10];   // equivalent declaration of arrT

arrT *func(int i) {
    static arrT num = {};
    return &num;
}

// function returning array is not allowed
// int *funcWrong()[10] { 
// }


// Using a Trailing Return Type
auto func2(int i) -> int(*)[10] {
    static int nums[10] = {};
    return &nums;
}

// Using decltype
int odd[] = {1, 3, 5, 7, 9, };
int even[] = {0, 2, 4, 6, 8, };

decltype(odd) *arrPtr(int i) {
    return i % 2 ? &odd : &even;
}
