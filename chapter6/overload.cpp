#include <string>

using std::string;

/*
 * Functions that have the same neme but different parameter lists and that appear in the same scope
 * are overloaded.
 * 
 * The `main` function may not be overloaded.
 * 
 * Overloaded functions must differ in the number or the type(s) of their parameters.
 * Moreover, a parameter that has a top-level const is indistinguishable from one without a top-level const.
 * 
 * 
 * Calling an Overloaded Function
 * 
 * Function calling(also known as overload resolution) is the process by which a particular function call
 * is associated with a specific function from a set of overloaded functions.
 * 
 * 
 * Overloading and Scope: Names Do Not Overload across Scopes
 * 
 * As usual, if we declare a name in an inner scope, that name hides uses of that name declared in an outer
 * scope. Names do not overload across scopes. In C++, name lookup happens before type checking, once a name is
 * found, the compiler ignores uses of that name in any outer scope.
 */


// determing whether two parameter types differ

int lookup(const int &i);   // parameter names are only a documentation aid
int lookup(const int &);    // error: parameter names are ignored


// two parameters that only differ in that one uses an alias and another uses a type to which
// the alias corresponds are not different.
typedef double number;
int lookup(const double&);
int lookup(const number&);    // error: number and double are the same type

int lookup(int);
int loopup(const int);        // error: redeclares

// the compiler will prefer the nonconst version when we pass a nonconst object or pointer to nonconst
int lookup(int *);
int lookup(const int *);    // ok, new function


// const_cast and overloading
// using const_cast to get plain reference(or pointer) from functions that have const parameters

const string &shorterString(const string &s1, const string &s2) {
    return s1.size() > s2.size() ? s2 : s1;
}

// overload the original shorterString function
string &shorterString(string &s1, string &s2) {
    auto &r = shorterString(const_cast<const string &>(s1), 
                            const_cast<const string &>(s2));
    // we know the original s1/s2 is plain reference, so here we can cast it back safely
    return const_cast<string &>(r);
}

void test() {
    string s1("you"), s2("are");
    const string &crs1 = s1, &crs2 = s2;
    string &rs1 = s1, &rs2 = s2;

    string &shorter = shorterString(s1, s2);
}

string read() {
    return "";
}
void print(const string &) {
    ;
}
void print(double) {
    ;
}

int print(int) {
    return 1;
}

void fooBar(int ival)
{
    bool read = false;  // new scope: hides the outer declaration of read
    // string s = read();  // error: read is a bool variable, not a function
    // bad pratice: usually it's a bad idea to declare functions at local scope
    int print(int);
    // print("Value: ");   // error: print(const string &) is hidden
    print(ival);        // ok: print(int) is visible
    print(3.14);        // ok: calls print(int); print(double) is hidden
}

// the matching between declaration and definition

// the top-level `const` doesn't influence the matching between declaration and definition  
int f2(int rr[]);
int f2(const int r[]) {
    return 0;
}

// ok
int f3(int *r);
int f3(int r[]) {
    return 0;
}

// ok
int f4(int (*)(int));
int f4(int (int)) {
    return 0;
}

// ok
int f5(int a[5]);
int f5(int *a) {
    return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
