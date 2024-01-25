#include <string>
#include <iostream>
#include "../chapter13 Copy Control/StrVec.h"
using namespace std;
/*
 * A variadic template is a template function or class that can take a varying number
 * of parameters. The varying parameters are known as a parameter pack. There are
 * two kinds of parameter packs: A template parameter pack represents zero or more
 * template parameters, and a function parameter pack represents zero or more
 * function parameters.
 * 
 * In a template parameter list, class... or typename... indicates that the
 * following parameter represents a list of zero or more types; the name of a type
 * followed by an ellipsis represents a list of zero or more nontype parameters of the
 * given type. In the function parameter list, a parameter whose type is a template
 * parameter pack is a function parameter pack. 
 * 
 * 
 * 
 * The sizeof... Operator
 * 
 * When we need to know how many elements there are in a pack, we can use the
 * sizeof... operator. Like sizeof (§ 4.9, p. 156), sizeof... returns a constant
 * expression (§ 2.4.4, p. 65) and does not evaluate its argument.
 * 
 * 
 * 
 * Writing a Variadic Function Template
 * 
 * Variadic functions are often recursive (§ 6.3.2, p. 227). The first call processes the
 * first argument in the pack and calls itself on the remaining arguments.
 * 
 * 
 * 
 * Pack Expansion
 * 
 * Aside from taking its size, the only other thing we can do with a parameter pack is to
 * expand it. When we expand a pack, we also provide a pattern to be used on each
 * expanded element.  We trigger an expansion by
 * putting an ellipsis (. . . ) to the right of the pattern.
 * 
 * Understanding Pack Expansions
 * 
 * More complicated patterns are also possible when we expand a
 * function parameter pack.
 * 
 * Note
 * The pattern in an expansion applies separately to each element in the pack.
 * 
 * 
 * 
 * Forwarding Parameter Packs
 * 
 * As we’ve seen, preserving type information is a two-step process. 
 * First, to preserve type information in the arguments, we must define 
 * emplace_back’s function parameters as rvalue references to a template 
 * type parameter.
 * 
 */

// Args is a template parameter pack; rest is a function parameter pack
// Args represents zero or more template type parameters
// rest represents zero or more function parameters
template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest) {}

template<typename T, typename ... Args> void g(T t, Args ... args) {
    cout << sizeof...(Args) << endl; // number of type parameters
    cout << sizeof...(args) << endl; // number of function parameters
}

// function to end the recursion and print the last element
// this function must be declared before the variadic version of print is defined
template<typename T>
ostream &print(ostream &os, const T &t)
{
    return os << t << endl;;        // no separator after the last element in the pack
}

// this version of print will be called for all but the last element in the pack
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
    os << t << ", ";                // print the first argument
    return print(os, rest...);      // recursive call; print the other arguments
}

class Test
{};

std::ostream &operator<<(std::ostream &os, const Test &t)
{
    return os << "-------------";
}

// call debug_rep on each argument in the call to print
template <typename... Args>
ostream &errorMsg(ostream &os, const Args&... rest)
{
    // print(os, debug_rep(a1), debug_rep(a2), ..., debug_rep(an)
    return print(os, rest...);
    // return os;
}

template <class... Args>
inline
void StrVec::emplace_back(Args&&... args)
{
    chk_n_alloc(); // reallocates the StrVec if necessary
    alloc.construct(first_free++, std::forward<Args>(args)...);
}

int main(int argc, char const *argv[])
{
    /* code */
    int i = 0; double d = 3.14; string s = "how now brown cow";
    g(i, i, i, s, 42, d);   // three parameters in the pack   5 5 
    g(s, 42, "hi");         // two parameters in the pack     3 3
    g(d, s);                // one parameter in the pack      2 2
    g("hi");                // empty pack                     1 1

    print(std::cout, "you", "will", "never", "lose");
    print(std::cout, "test", Test());

    errorMsg(std::cout, "I", "am", "the", "one");
    return 0;
}
