#include <string>

using std::string;

/*
 * A function's type is determined by its return type and the types of its parameters.
 * The function's name is not part of its type.
 * 
 * There is no need to dereference the function pointer. When we use the name of a function
 * as a value, the function is automatically converted to a pointer.
 * 
 * We can assign nullptr or a zero-valued integer constant expression to a function
 * pointer to indicate that the pointer does not point to any function.
 * 
 * There is no conversion between pointers to one function type and pointers
 * to another function type.
 *
 * 
 * When we declare a pointer to an overloaded function, the type of the pointer must match 
 * one of the overloaded functions exactly. 
 * 
 * 
 * Function Pointer Parameters
 * 
 * As with arrays, we can write a parameter that looks like a function type, but
 * it will be treated as a pointer. 
 * 
 * 
 * Returning a Pointer to Function
 * 
 * Unlike what happens to parameters that have function type, the return type is not
 * automatically converted to a pointer type. 
 */ 


void ff(int *);
void ff(unsigned int);

void (*pf)(unsigned int) = ff;
// void (*pf2)(int) = ff;   // error: no ff with a matching parameter list

void useBigger(const string &s1, const string &s2,
               bool pf(const string &, const string &));

// equivalent declaration: explicitly define the parameter as a pointer to function
void useBigger(const string &s1, const string &s2,
               bool (*pf)(const string &, const string &));


// using alias to simplify the declaration of function pointer
typedef bool (*FuncP)(const string &, const string &);
using FuncP = bool (*)(const string &, const string &);

// Func has function type
typedef bool Func(const string &, const string &);
using Func = bool (const string &, const string &);

FuncP f1(int i);    // ok
// Func f1(int i);     // error: function returning function is not allowed
// Func &f1(int i);    // error: can not overload function by return type
Func *f1(int i);

// we can also declare f1 directly
int (*(f1)(int i, int j))(int *, int);

// or using a trailing return
auto f1(int i, int j) -> int (*)(int *, int);