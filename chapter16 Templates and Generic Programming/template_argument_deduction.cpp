#include <utility>
#include <type_traits>
#include <string>
#include <iostream>

using namespace std;

/*
 * Conversions and Template Type Arguments
 * 
 * Functions parameters whose type uses a template type parameter have
 * sepcial initialization rules. Only a very limited number of conversions are
 * automatically applied to such arguments. Rather than converting the arguments,
 * the compiler generates a new instantiation.
 * 
 * Except for the top-level consts, the only other conversions performed in a call
 * to a function template are:
 *  1.monodirectional low-level const conversions (reference or pointer)
 *  2.Array- or function-to-pointer conversions. If the function parameter is not a 
 *  reference type, then the normal pointer conversion will be applied to arguments
 *  of array and function type.
 * 
 * Other conversions, such as the arithmetic conversions, derived-to-base, and user-defined
 * conversions, are not performed.
 * 
 * 
 * Note
 * `const` conversions and array or function to pointer are the only automatic
 * conversions for arguments to parameters with template types.
 * 
 * 
 * Function Parameters That Use the Same Template Parameter Type
 * 
 * Because there are limited conversions, the arguments to such parameters
 * must have essentially the same type. If the deduced types do not match, then the call
 * is an error. 
 * 
 * 
 * 
 * Function-Tempalte Explicit Arguments
 * 
 * explicit template argument.
 * An explicit template argument may be omitted only for the trailing 
 * (right-most) parameters, and then only if these can be deduced
 * from the function parameters.
 * 
 * 
 * Normal Conversions Apply for Explicitly Specified Arguments
 * 
 * 
 * 
 * Trailing Return Types and Type Transformation
 * 
 * template <typename It>
 * auto fcn(It beg, It end) -> decltype(*beg);
 * 
 * The dereference operator returns an lvalue, so the type deduced by
 * decltype is a reference to the type of the element that beg denotes.
 * 
 * 
 * 
 * The Type Transformation Library Template Classes
 * 
 * To obtain the element type (as opposed to references to elements),
 * we can use a library `type transformation template`. These templates are
 * defined in the type_traits header.
 * 
 * In genegral the classes in type_traits are used for so-called template
 * metaprogramming.
 * Using remove_reference and a trailing return with `decltype`, we can write
 * our function to return a copy of an element's value.
 * 
 * 
 * 
 * Function Pointers and Argument Deduction
 * 
 * When we initialize or assign a function pointer from a function template,
 * the compiler uses the type of the pointer to deduce the template arguments.
 * 
 * int (*pf1) (const int &, const int &) = compare;
 * 
 * It is an error if the template arguments cannot be determined from the fuction
 * pointer type.
 * 
 * 
 * 
 * Template Argument Deduction and References
 * 
 * 
 * Type Deduction from Lvalueb Reference Function Parameters
 * 
 * When a function parameter is an ordinary (lvalue) reference to a template  type
 * parameter (i.e., that has the form T &), the binding rules say that we can 
 * pass only an lvalue.
 * 
 * If a function parameter has type const T &, normal binding rules say that we can 
 * pass any kind of argument. (including rvalues)
 * 
 * 
 * Type Deduction from Rvalue Reference Function Parameters
 * 
 * When a function parameter is an rvalue reference, normal binding rules say that
 * we can pass rvalue to this parameter.
 * 
 * 
 * Reference Collapsing and Rvalue Reference Parameters
 * 
 * The language defines two exceptions to normal binding rules that allow to bind
 * an rvalue reference to an lvalue. These exceptions are the foundation for how
 * library facilities such as `move` operate.
 * 
 * The first exception affects how type deduction is done for rvalue reference parameters.
 * When we pass an lvalue to "T &&", the compiler deduces the template type parameter
 * as the argument's lvalue reference type. So,  when we call f3(i) (void f3(T &&)), the 
 * compiler deduces the type of T as int &, not int.
 * 
 * Ordinarily, we cannot (direct) define a reference to a reference. However. it is
 * possible to do so indirectly through a type alias or through a template type parameter.
 * 
 * The second exception to the normal binding rules: If we indirectly create a reference
 * to a reference, then those references "collapse". In all but one case, the references
 * collapse to form an ordinary lvalue reference type. References collapse to form an 
 * rvalue reference only in the specific case of an rvalue reference to an rvalue reference.
 * 
 * Note
 * An argument of any type can be passed to a function parameter that is an rvalue
 * reference to a template parameter type (T &&). When an lvalue is passed to such a parameter,
 * the function paramerer is instantiated as an ordinary, lvalue reference (T &).
 * 
 * 
 * Writing Template Functions with Rvalue Reference Parameters
 * 
 * The fact that the template parameters can be deduced to a reference type can have
 * surprising impacts on the code inside the template:
 * 
 *      template <typename T> void f3(T&& val)
 *      {
 *          T t = val;  // copy or binding a reference
 *          t = fcn(t); // does the assignment change only t or val and t?
 *          if (val == t) { ... }  // always true if T is reference type
 *      }
 * 
 * When we call f3 on an rvalue, such as the literal 42, 
 * the function has no idea about the T is a `int` or `int &`.
 * 
 * template <typename T> void f(T&&);       // binds to nonconst rvalues
 * template <typename T> ovid f(const T&);  // binds to const rvalues
 * 
 * 
 * 
 * Understanding std::move
 * 
 * static_cast from an Lvalue to an Rvalue Reference Is Permitted
 * 
 * static_cast<T &&> (t) == std::move(t);
 * 
 * 
 * 
 * Forwarding
 * 
 * Defining Function Parameters That Retain Type Information
 * 
 * We can preserve all the type information in an argument by defining its 
 * corresponding function parameter as an rvalue reference to a template type parameter.
 * 
 * Using std::forward to Preserve Type Information in a Call
 * 
 * Unlike move, forward must be called with an explicit argument type. That is,
 * the return type of forward<T> is T &&.
 * 
 * Ordinarily, we use forward to pass a function parameter that is defined as an rvalue
 * reference to a template type parameter.
 * 
 * template <typename Type> intermediary(Type &&arg)
 * {
 *      finalFcn(std::forward<Type>(arg));
 * }
 * 
 */

template <typename T> T func1(T, T);    // arguments are copied
template <typename T> int func2(const T &, const T &);            // reference
template <typename T> T func3(const T(&)[10], const T(&)[10]);  // reference of array
template <typename It> auto fcn(It beg, It end) -> decltype(*beg);
template <typename T> int func6(T &, T &);            // reference
template <typename T> int func7(T &);
template <typename T> int func8(const T &);
int func9(int &&);

/*
 * Note that `type` is member of a class that depends on a template parameter. As a result,
 * we must use `typename` in the declaration of the return type to tell the compiler
 * that `type` represents a type.
 */
template <typename It> auto fcn(It beg, It end) -> typename remove_reference<decltype(*beg)>::type;

template <typename T1, typename T2, typename T3>

T1 sum(T2, T3);

template <typename T> int compare(const T &, const T &);

int main(int argc, char const *argv[])
{
    string s1;
    const string s2;
    func1(s1, s2);
    func2(s1, s2);
    func6(s2, s2);

    // the arrays have different size, so they have different types.
    int a[10], b[42], c[10];
    func1(a, b);
    // func2(a, b); // error: array types don't match
    /*
     * If pass the arguments by value, then the array will be 
     * converted to the pointer to the elements. If pass by reference, then the
     * array will be converted to the reference to array (different size of array will
     * lead to different type).
     */
    func2(a, c);    
    func2(2, 3);
    func3(a, c);    // ok
    
    const auto &temp = a;   // auto can deduce the array type
    auto &temp2 = a;        // but the `template argument deduction` can't

    // Specifying an Explicit Template Argument
    // This call explicitly specifies the type for T1. The compiler will deduce
    // the types for T2 and T3 from the types of s1 and s2.
    sum<long long> (s1, s2);

    // overloaded versions of func; 
    void func5(int (*)(const string &, const string &));
    void func5(int (*)(const int &, const int &));
    // func5(compare); // more than one instance of overloaded function "func5" matches the argument list

    const int &i = 8;
    func7(i);
    func8(3);

    int &&y = 9;

    return 0;
}
