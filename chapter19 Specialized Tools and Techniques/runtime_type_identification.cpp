#include <iostream>
#include <typeinfo>
/**
 * The dynamic_cast Operator
 * 
 * A dynamic_cast has the following form:
 * dynamic_cast<type*>(e)
 * dynamic_cast<type&>(e)
 * dynamic_cast<type&&>(e)
 * where type must be a class type and (ordinarily) names a class that has virtual
 * functions. In the first case, e must be a valid pointer (§ 2.3.2, p. 52); in the second, e
 * must be an lvalue; and in the third, e must not be an lvalue.
 * 
 * In all cases, the type of e must be either a class type that is publicly derived from
 * the target type, a public base class of the target type, or the same as the target
 * type. If e has one of these types, then the cast will succeed. Otherwise, the cast fails.
 * 
 * If a dynamic_cast to a pointer type fails, the result is 0. If a dynamic_cast to a
 * reference type fails, the operator throws an exception of type bad_cast.
 * 
 * 
 * Pointer-Type dynamic_casts
 * 
 * if (Derived *dp = dynamic_cast<Derived*>(bp))
 * {
 *  // use the Derived object to which dp points
 * } else { // bp points at a Base object
 *  // use the Base object to which bp points
 * }
 * 
 * Note
 * We can do a dynamic_cast on a null pointer; the result is a null pointer of
 * the requested type.
 * 
 * It is worth noting that we defined dp inside the condition. By defining the variable in
 * a condition, we do the cast and corresponding check as a single operation. Moreover,
 * the pointer dp is not accessible outside the if. If the cast fails, then the unbound
 * pointer is not available for use in subsequent code where we might forget to check
 * whether the cast succeeded.
 * 
 * Best Practices
 * Performing a dynamic_cast in a condition ensures that the cast and test of
 * its result are done in a single expression.
 * 
 * 
 * Reference-Type dynamic_casts
 * 
 * When a cast to a reference type fails, the cast throws a
 * std::bad_cast exception, which is defined in the typeinfo library header.
 * 
 * void f(const Base &b)
 * {
 *      try { const Derived &d = dynamic_cast<const Derived&>(b);
 *      // use the Derived object to which b referred
 *      } catch (bad_cast) {
 *      // handle the fact that the cast failed
 *      }
 * }
 * 
 * 
 * The typeid Operator
 * 
 * The typeid operator allows a program to ask of an expression: 
 * What type is your object?
 * 
 * A typeid expression has the form typeid(e) where e is any expression or a type
 * name. The result of a typeid operation is a reference to a const object of a library
 * type named type_info, or a type publicly derived from type_info. 
 * 
 * The typeid operator can be used with expressions of any type. As usual, top-level
 * const (§ 2.4.3, p. 63) is ignored, and if the expression is a reference, typeid
 * returns the type to which the reference refers. When applied to an array or function,
 * however, the standard conversion to pointer (§ 4.11.2, p. 161) is not done. That is, if
 * we take typeid(a) and a is an array, the result describes an array type, not a
 * pointer type.
 *
 * When the operand is not of class type or is a class without virtual functions, then
 * the typeid operator indicates the static type of the operand. When the operand is an
 * lvalue of a class type that defines at least one virtual function, then the type is
 * evaluated at run time.
 * 
 * 
 * Using the typeid Operator
 * 
 * 
 * Warning
 * The typeid of a pointer (as opposed to the object to which the pointer
 * points) returns the static, compile-time type of the pointer.
 * 
 * Whether typeid requires a run-time check determines whether the expression is
 * evaluated. The compiler evaluates the expression only if the type has virtual functions.
 * 
 * If p is a null pointer, then typeid(*p) throws a bad_typeid exception.
 * 
 * 
 * Using RTTI
 * 
 * We’ll define an equality operator whose parameters are references to the base-class
 * type. The equality operator will use typeid to verify that the operands have the
 * same type. If the operands differ, the == will return false. Otherwise, it will call a
 * virtual equal function. Each class will define equal to compare the data elements of
 * its own type. These operators will take a Base& parameter but will cast the operand
 * to its own type before doing the comparison.
 * 
 * 
 * The type_info Class
 * 
 * t1 == t2
 * t1 != t2
 * t.name()         system-dependent. The only guarantee we have about the 
 *                  return from name is that it returns a unique string for each type.
 * t1.before(t2)    Return a bool that indicates whether t1 comes before t2.
 *                  The ordering imposed by before is compiler dependent.
 * 
 * 
 * Note
 * The type_info class varies by compiler. Some compilers provide additional
 * member functions that provide additional information about types used in a
 * program. You should consult the reference manual for your compiler to
 * understand the exact type_info support provided.
 */

class Base 
{
public:
    virtual ~Base() {}
    virtual bool equal(const Base &) const = 0;
};

class Derived : public Base
{
public:
    virtual bool equal(const Base &) const;
};

// global function
bool operator==(const Base &lhs, const Base &rhs)
{
    return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

bool Derived::equal(const Base &rhs) const 
{
    auto &r = dynamic_cast<const Derived &>(rhs);
    // do the work to compare two Derived objects and return the result
    return true;
}

int main(int argc, char const *argv[])
{
    Base *bp = new Derived;

    if (Derived *dp = dynamic_cast<Derived *>(bp))
    {
        // using dp
    }
    else
    {
        // using bp
    }

    delete bp;

    Derived d;
    Base &br = d;

    try
    {
        Derived &dr = dynamic_cast<Derived &>(br);
    }
    catch(const std::bad_cast &e)
    {
        std::cerr << e.what() << '\n';
    }

    Derived *dp = new Derived;
    if (typeid(*dp) == typeid(*bp))
    {

    }
    if (typeid(*bp) == typeid(Derived))
    {

    }

    return 0;
}
