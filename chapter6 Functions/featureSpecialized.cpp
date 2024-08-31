#include <iostream>
#include <string>
#include <cassert>

using std::string;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

/*
 * Default Arguments
 *
 * The rules is like python. Part of the work of designing a function with default arguments is
 * ordering the parameters so that those least likely to use a default value appear first and those
 * most likely to use a default appear last.
 * 
 * 
 * Default Argument Declarations
 * 
 * Each parameter can have its default specified only once in a given scope. Thus, any subsequent
 * declaration can add a default only for a parameter that has not previously had a default specified.
 * Default arguments ordinarily should be specified with the function declaration in an appropriate header.
 * 
 * 
 * Default Argument Initializers
 * 
 * Local variables may not be used as a default argument. Excepting that restriction, a default argument
 * can be any expression that has a type that is convertible to the type of the parameter.
 * 
 * Names used as default arguments are resolved in the scope of the function declaration. The value that
 * those names represent is evaluated at the time of the call.!!!
 * 
 * 
 * Inline and constexpr Functions
 * 
 * Inline functions avoid funciton call overhead. A function specified as inline (usually) is expanded
 * "in line" at each call. The run-time overhead of making shorterString a function is thus removed. 
 * The inline specification is only a request to the compiler. The compiler may choose to ignore this
 * request. Many compilers will not inline a recursive function. A 75-line function will almost surely not
 * be expanded inline.
 * 
 * 
 * constexpr Functions
 * 
 * A constexpr function is a function that can be used in a constant expression. A constexpr
 * function is defined like any other function but must meet certain restrictions(C++11): The return type
 * and the type of each argument must be a literal type, and the function body must contain exactly
 * one return statement. You can use ternary operator and recursion to make powerful constexpr function.
 * 
 * In C++14, the constexpr functions behave almost like ordinary functions, they can have:
 * 1. conditional jump instructions or loop instructions.
 * 2. more than one instruction.
 * 3. constexpr functions.
 * 4. fundamental data types (literal types) that have to be initialized with a constant expression.
 * 
 * In C++14, the constexpr functions are mostly like `pure functions` in functional programming paradigm.
 * 
 * The compiler will replace a call to a constexpr function with its resulting value if you take 
 * the return value as a constant expression, otherwise, it will be executed at runtime. A constexpr 
 * function body may contain other statements so long as those statements generate no actions at
 * run time. Those statements contain null statements, type alias, and using declarations.
 * 
 * A constexpr function is permitted to return a value that is not a constant.
 * 
 * The compiler will produce an error messge if we use a constexpr function that does not return 
 * constant expression where a constant expression is needed.
 * 
 * The constexpr function is implicitly inline.
 * 
 * 
 * Put inline and constexpr Functions in Header Files
 * 
 * inline and constexpr functions may be defined multiple times in the program because the compiler
 * needs the definition, not just the declaration, in order to expand the code. However , all of the
 * definiitons of a given inline or constexpr must match exactly. As a result, inline and constexpr
 * functions normally are defined in headers.
 * 
 * 
 * Aids for Debugging
 * 
 * The assert Preprocessor Macro is defined in the cassert header.
 * The behavior of assert depends on the status of a preprocessor variable named NDEBUG.
 * If NDEBUG is defined, assert does nothing. By default, NDEBUG is not defined, so,
 * by default, assert performs a run-time check. The assert macro is often u
 * 
 * We can mannually define NDEBUG preprocessor variable or use the command-line option by adding "-D NDEBUG".
 * We might use the following constants to report additional information in error messages.
 * __func__: a static array of const char, defined by compiler to hold the name of the current function
 * __FILE__: defined by preprocessor: the name of the file
 * __LINE__: current line number
 * __TIME__: the time the file was compiled
 * __DATE__: the date the file was compiled
 */

int i = 2;
extern int i;


typedef string::size_type sz;

string screen(sz, sz, char = ' ');
// string screen(sz, sz, char = '*');      // error: redeclaration
string screen(sz = 24, sz = 80, char);     // ok: adds default arguments
string screen3();

// a default can be any expression(excepting local variables) that has a type that is convertible
// to the type of the parameter

sz wd = 80;
char def = ' ';
sz ht();
string screen2(sz = ht(), sz = wd, char = def);
string window = screen3();

sz ht() {
    return 22;
}

string screen(sz, sz, char) {
    return "I don't know";
}

string screen2(sz, sz, char) {
    return "yes";
}

string screen3() {
    string s;
    cin >> s;
    return s;
}

void f2() {
    def = '*';              // changes the value of a default argument
    sz wd = 100;            // hides the outer definition of wd but does not change the default

    // because the compiler does not know the address of local variables at compile-time,
    // so the local variables is now allowed to be initializers of default arguments. And so
    // the local wd above dones not change the default.

    window = screen2();     // calls screen(ht(), 80, '*')
}

// inline function
inline const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

// constexpr function
constexpr int new_sz() { return 42; }
constexpr int foo = new_sz();

// the scale function will return a constant expression if its argument is a constant expression
// but not otherwise. A constexpr function is not required to return a constant expression
constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }

// the compiler will replace the call to scale with the resulting value
int arr[scale(2)];
// int i = 2;
// int a2[scale(i)];   // error: scale(i) is not a constant expression

int func(int i, const string &s = "") {
    cout << i << " " << s << endl;
    int res = new_sz();
    return res;
}

int main(int argc, char const *argv[])
{
    cout << i << endl;
    cout << screen() << endl;
    cout << screen2() << endl;
    // write our own conditional debugging code using NDEBUG
    #ifndef NDEBUG
    cerr << __func__ << endl;
    #endif
    cout << window << endl;

    func(2);
    return 0;
}

int cal(int i) {
    std::cout << "sdd" << std::endl;
    return i * i;
}

// this is not allowed in C, because cal(3) is not constant expression
// but it's ok in C++! 
int j = cal(3);

