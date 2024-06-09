#include <string>
#include <iostream>

/*
 * Classes, Namespaces, and Scope
 *
 * When a class is wrapped in a namespace, the normal lookup still happens: When a
 * name is used by a member function, look for that name in the member first, then
 * within the class (including base classes), then look in the enclosing scopes, one or
 * more of which might be a namespace.
 * 
 * Tip
 * The order in which scopes are examined to find a name can be inferred from
 * the qualified name of a function. The qualified name indicates, in reverse
 * order, the scopes that are searched.
 * 
 *  
 * 参数依赖查找
 * Argument-Dependent Lookup and Parameters of Class Type
 * 
 * This operator>> function is defined by the string library, which in turn is defined
 * in the std namespace. Yet we can we call operator>> without an std:: qualifier
 * and without a using declaration.
 * 
 * We can directly access the output operator because there is an important exception
 * to the rule that names defined in a namespace are hidden. When we pass an object of
 * a class type to a function, the compiler searches the namespace in which the
 * argument’s class is defined in addition to the normal scope lookup. This exception also
 * applies for calls that pass pointers or references to a class type.
 * 
 * 
 * Lookup and std::move and std::forward
 * 
 * So long as we write std::move rather than move, we know that we
 * will get the version from the standard library.
 * 
 *
 * Friend Declarations and Argument-Dependent Lookup
 * 
 * Recall that when a class declares a friend, the friend declaration does not make the
 * friend visible (§ 7.2.1, p. 270). However, an otherwise undeclared class or function
 * that is first named in a friend declaration is assumed to be a member of the closest
 * enclosing namespace. The combination of this rule and argument-dependent lookup
 * can lead to surprises:
 * 
 * namespace A { 
 * class C {
 *      // two friends; neither is declared apart from a friend declaration
 *      // these functions implicitly are members of namespace A
 *      friend void f2();        // won't be found, unless otherwise declared
 *      friend void f(const C&); // found by argument-dependent lookup
 * };
 * }
 * 
 * 
 * 
 * Overloading and Namespaces
 * 
 * Argument-Dependent Lookup and Overloading
 * 
 * Each namespace that defines a
 * class used as an argument (and those that define its base classes) is searched for
 * candidate functions. Any functions in those namespaces that have the same name as
 * the called function are added to the candidate set. These functions are added even
 * though they otherwise are not visible at the point of the call.
 * 
 * 
 * Overloading and using Declarations
 * 
 * To understand the interaction between using declarations and overloading, it is
 * important to remember that a using declaration declares a name, not a specific
 * function. When we write a using declaration for a function, all the versions of 
 * that function are brought into the current scope.
 * 
 * 
 * Overloading and using Directives
 * 
 * A using directive lifts the namespace members into the enclosing scope. If a
 * namespace function has the same name as a function declared in the scope at which
 * the namespace is placed, then the namespace member is added to the overload set.
 * 
 * 
 * Overloading across Multiple using Directives
 * 
 * If many using directives are present, then the names from each namespace become
 * part of the candidate set;
 * 
 * 
 */

namespace A
{
class Test
{
    friend void f() {}
    friend void f2(const Test &t) {}
};
}

struct Node
{
    int v, cost, k;
    friend bool operator<(const Node &n1, const Node &n2)
    {
        return n1.cost < n2.cost;
    }

    friend bool done() { return false; }
};

struct Derived : Node
{
};

struct DD : Derived
{
    /* data */
};


int main(int argc, char const *argv[])
{
    A::Test test;
    f2(test);
    int t = 1;
    // move(t);     // t is not a class type, so the compiler will not lookup the t's scope.

    DD d1, d2;
    d1 < d2;
    // done();
    move(std::string());
    return 0;
}
 

