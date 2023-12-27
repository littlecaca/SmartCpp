#include "string.h"
#include <string>
#include <iostream>

/*
 * About Templates
 *
 * Both object-oriented programming (OOP) and generic programming deal with types
 * that are not known at the time the program is written. The distinction between the
 * two is that OOP deals with types that are not known until run time, whereas in
 * generic programming the types become known during compilation.
 *
 *
 *
 * Defining A Template
 *
 * Function Templates
 *
 * A function template is a formula from which we can generate type-specific
 * versions of that function.
 *
 * Note
 * In a template definition, the template parameter list cannot be empty.
 *
 * Instantiating a Function Template
 *
 * When we call a function template, the compiler (ordinarily) uses the arguments of the
 * call to deduce the template argument(s) for us.
 *
 *
 *
 * Template Type Parameters
 *
 * Each type parameter must be preceded by the keyword `class` or `typename`.
 * These keywords have the same meaning and can be used interchangeably inside a
 * template parameter list.
 *
 *
 *
 * Nontype Template Parameters
 *
 * A nontype parameter represents a value rather than a type.
 * When the template is instantiated, nontype parameters are replaced with a value
 * supplied by the user or deduced by the compiler. These values must be constant
 * expressions.
 *
 * Nontype parameters are specified by using a specific type name instead of the class or
 * typename keyword.
 *
 * A nontype parameter may be an integral type, or a pointer or (lvalue) reference to
 * an object or to a function type.
 *
 * We may not use an ordinary
 * (nonstatic) local object or a dynamic object as a template argument for reference
 * or pointer nontype template parameters. A pointer parameter can also be instantiated
 * by nullptr or a zero-valued constant expression.
 *
 *
 *
 * `inline` and `constexpr` Function Templates
 *
 * The inline or constexpr specifier follows the template
 * parameter list and precedes the return type.
 *
 *
 *
 * Writing Type-Independent Code
 *
 * Best Pratices
 *
 * Template programs should try to minimize the number of requirements
 * placed on the argument types.
 * 
 *
 *
 * Template Compilation
 *
 * When the compiler sees the definition of a template, it does not generate code.
 * The fact that code is generated only when we use a template.
 * 
 * To generate an instantiation, the compiler needs to have
 * the code that defines a function template or class template member function. As a
 * result, unlike nontemplate code, headers for templates typically include definitions as
 * well as declarations.
 * 
 * The fact that code is not generated until a template is instantiated affects when we
 * learn about compilation errors in the code inside the template. In general, there are
 * three stages during which the compiler might flag an error.
 * 
 * The first stage is when we compile the template itself. The compiler can detect syntax
 * errors.
 * 
 * The second error-detection time is when the compiler sees a use of the template. The
 * compiler can check whether the number and type of the arguments is appropriate.
 * 
 * The third time when errors are detected is during instantiation. It is only when
 * that type-related errors can be found.
 * 
 */

template <typename T>
int compare(const T &lhs, const T &rhs)
{
    // version of compare that will be correct even if used on pointers
    if (std::less<T>()(lhs, rhs))
        return -1;
    if (std::less<T>()(rhs, lhs))
        return 1;
    return 0;
}

// Nontype parameter, need to indicate the specific type
template <unsigned M, unsigned N>
int compare(const char (&p1)[M], const char (&p2)[N])
{
    return strcmp(p1, p2);
}

template <typename T>
int func() {
    T as = 1;
    return as + as;
}


int main(int argc, char const *argv[])
{
    std::string s1 = "Hello", s2 = "cpp";
    std::cout << compare(2, 32) << std::endl;
    std::cout << compare(s1, s2) << std::endl;

    // The compiler can deduce the M and N according to the size of the literals
    std::cout << compare("this", "insane") << std::endl;

    // The fucntion template parameters don't have to be the parameters of function
    std::cout << func<int>() << std::endl;

    class Test {};
    // compare(Test(), Test());

    return 0;
}
