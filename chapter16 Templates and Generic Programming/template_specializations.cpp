#include <cstring>
#include <string>
#include <iostream>
#include "..\chapter7 Classes\adt.h"
using namespace std;
/*
 * When we can’t (or don’t want to) use the
 * template version, we can define a specialized version of the class or function template.
 *
 * A specialization is a separate
 * definition of the template in which one or more template parameters are specified to
 * have particular types.
 *
 *
 * Defining a Function Template Specialization
 *
 * To indicate that we are specializing a template, we
 * use the keyword template followed by an empty pair of angle brackets (< >). The
 * empty brackets indicate that arguments will be supplied for all the template
 * parameters of the original template
 *
 * When we define a specialization, the function parameter type(s) must match the
 * corresponding types in a previously declared template.
 *
 *
 * Function Overloading versus Template Specialization
 *
 * It is important to realize that a specialization is
 * an instantiation; it is not an overloaded instance of the function name.
 *
 * Note
 * Specializations instantiate a template; they do not overload it. As a result,
 * specializations do not affect function matching.
 *
 *
 * Remember that: the array is equally good to the pointer to its elements.
 *
 *
 * Key Concept: Ordinary Scope Rules Apply to Specializations
 *
 * It is an error for a program to use a specialization and an instantiation of
 * the original template with the same set of template arguments. However, it is
 * an error that the compiler is unlikely to detect.
 *
 *
 * Best Practices
 *
 * Templates and their specializations should be declared in the same
 * header file. Declarations for all the templates with a given name should
 * appear first, followed by any specializations of those templates.
 *
 *
 * Class Template Specializations
 *
 * Just look the example of hash<Sales_data>
 * 
 * Class-Template Partial Specializations
 *
 * Differently from function templates, a class template specialization does not have to
 * supply an argument for every template parameter. We can specify some, but not all,
 * of the template parameters or some, but not all, aspects of the parameters. 
 * 
 * A class template partial specialization is itself a template. 
 * 
 * Note
 * We can partially specialize only a class template. We cannot partially
 * specialize a function template.
 * 
 * The specialization’s template parameter list
 * includes an entry for each template parameter whose type is not completely fixed by
 * this partial specialization. 
 * 
 * After the class name, we specify arguments for the template
 * parameters we are specializing. These arguments are listed inside angle brackets
 * following the template name. The arguments correspond positionally to the parameters
 * in the original template.
 * 
 * 
 * Specializing Members but Not the Class
 * 
 * Just look the example below.
 */

// first version; can compare any two types
template <typename T>
int compare(const T &, const T &);

// second version to handle string literals
// the version with character array parameters is more specialized
template <size_t N, size_t M>
int compare(const char (&)[N], const char (&)[M]);

// special version of compare to handle pointers to character arrays
template <>
int compare(const char *const &p1, const char *const &p2)
{
    return strcmp(p1, p2);
}


// To enable users of Sales_data to use the specialization of hash, we
// should define this specialization in the Sales_data header.
namespace std
{
    template <>
    struct hash<Sales_data>
    {
        // the type used to hash an unordered container must define these types
        typedef size_t result_type;
        typedef Sales_data argument_type;

        size_t operator()(const Sales_data &s) const;

        // our class uses synthesized copy control and default constructor
    };

    size_t
    hash<Sales_data>::operator()(const Sales_data &s) const
    {
        return hash<string>()(s.bookNo) ^
               hash<unsigned>()(s.units_sold) ^
               hash<double>()(s.revenue);
    }
}

// If hash<Sales_data> uses the private members of Sales_data, we must
// make this class a friend of Sales_data
// template <class T> class std::hash; // needed for the friend declaration
// struct Sales_data
// {
// friend class std::hash<Sales_data>;
// };


// Class-Template Partial Specializations

// original, most general template
template <class T> struct remove_reference_
{
    typedef T type;
};

// partial specializations that will be used for lvalue and rvalue references
template <class T> struct remove_reference_<T &>
{
    typedef T type;
};

template <class T> struct remove_reference_<T &&>
{
    typedef T type;
};

// Specializing Members but Not the Class
template <class T> struct Foo
{
    Foo(const T &m = T()) : mem(m) { }
    void Bar(const T &) {}
    T mem;
};

template <> 
Foo<int>::Foo(const int &m) { }

template <> 
void Foo<int>::Bar(const int &) { }

int main(int argc, char const *argv[])
{
    // compare("you", "areth"); // The two literals must have different length
    // compare("you", "are");

    int i;
    // decltype(42) is int, uses the original template
    remove_reference_<decltype(42)>::type a;
    // decltype(i) is int&, uses first (T&) partial specialization
    remove_reference_<decltype(i)>::type b;
    // decltype(std::move(i)) is int&&, uses second (i.e., T&&) partial specialization
    remove_reference_<decltype(std::move(i))>::type c;

    return 0;
}
