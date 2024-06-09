#include <exception>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

/*
 * The noexcept Exception Specification
 *
 * Under the new standard, a function can specify that it does not throw exceptions by
 * providing a noexcept specification. The keyword noexcept following the function
 * parameter list indicates that the function won’t throw.
 * We say that recoup has a nonthrowing specification.
 *
 * The noexcept specifier must appear on all of the declarations and the
 * corresponding definition of a function or on none of them.
 * The specifier precedes a trailing return (§ 6.3.3, p. 229).
 *
 * We may also specify noexcept on the declaration
 * and definition of a function pointer. It may not appear in a typedef or type alias. In
 * a member function the noexcept specifier follows any const or reference qualifiers,
 * and it precedes final, override, or = 0 on a virtual function.
 *
 *
 *
 * Violating the Exception Specification
 *
 * It is important to understand that the compiler does not check the noexcept
 * specification at compile time. In fact, the compiler is not permitted to reject a function
 * with a noexcept specifier merely because it contains a throw or calls a function that
 * might throw (however, kind compilers will warn about such usages).
 *
 * If a noexcept function does throw, terminate is called, thereby enforcing
 * the promise not to throw at run time.
 *
 * As a result, noexcept should be used in two cases: if we are confident that the
 * function won’t throw, and/or if we don’t know what we’d do to handle the error
 * anyway.
 *
 *
 * Warning
 * The compiler in general cannot, and does not, verify exception specifications
 * at compile time.
 *
 *
 * Backward Compatibility: Exception Specifications
 * void recoup(int) noexcept; // recoup doesn't throw
 * void recoup(int) throw(); // equivalent declaration
 * These declarations of recoup are equivalent. Both say that recoup won’t
 * throw.
 *
 *
 *
 * Arguments to the noexcept Specification
 *
 * void recoup(int) noexcept(true); // recoup won't throw
 * void alloc(int) noexcept(false); // alloc can throw
 *
 *
 *
 * The noexcept Operator
 *
 * Arguments to the noexcept specifier are often composed using the noexcept
 * operator. The noexcept operator is a unary operator that returns a bool rvalue
 * constant expression that indicates whether a given expression might throw. Like
 * sizeof (§ 4.9, p. 156), noexcept does not evaluate its operand.
 *
 * We can use the noexcept operator to form an exception specifier as follows:
 * void f() noexcept(noexcept(g())); // f has same exception specifier as g
 *
 *
 * Note
 * noexcept has two meanings: It is an exception specifier when it follows a
 * function’s parameter list, and it is an operator that is often used as the bool
 * argument to a noexcept exception specifier.
 *
 *
 *
 * Exception Specifications and Pointers, Virtuals, and Copy Control
 *
 * Although the noexcept specifier is not part of a function’s type, whether a function
 * has an exception specification affects the use of that function.
 *
 * A pointer to function and the function to which that pointer points must have
 * compatible specifications. That is, if we declare a pointer that has a nonthrowing
 * exception specification, we can use that pointer only to point to similarly qualified
 * functions. A pointer that specifies (explicitly or implicitly) that it might throw can point
 * to any function, even if that function includes a promise not to throw.
 *
 * If a virtual function includes a promise not to throw, the inherited virtuals must also
 * promise not to throw. On the other hand, if the base allows exceptions, it is okay for
 * the derived functions to be more restrictive and promise not to throw.
 *
 * When the compiler synthesizes the copy-control members, it generates an exception
 * specification for the synthesized member. If all the corresponding operation for all the
 * members and base classes promise not to throw, then the synthesized member is
 * noexcept. If any function invoked by the synthesized member can throw, then the
 * synthesized member is noexcept(false). Moreover, if we do not provide an
 * exception specification for a destructor that we do define, the compiler synthesizes
 * one for us. The compiler generates the same specification as it would have generated
 * had it synthesized the destructor for that class.
 *
 *
 *
 * Exception Class Hierarchies
 *
 * The only operations that the exception types define are the copy constructor,
 * copy-assignment operator, a virtual destructor, and a virtual member named what.
 * The what function returns a const char* that points to a null-terminated character
 * array, and is guaranteed not to throw any exceptions.
 *
 * The exception, bad_cast, and bad_alloc classes also define a default
 * constructor. The runtime_error and logic_error classes do not have a default
 * constructor but do have constructors that take a C-style character string or a library
 * string argument.
 * 
 * The second layer specializes exception into two broad categories: run-time or
 * logic errors. Run-time errors represent things that can be detected only when the
 * program is executing. Logic errors are, in principle, errors that we could have detected
 * in our application.
 *
 * 
 * Using Our Own Exception Types
 * 
 * 
 *
 */

// hypothetical exception classes for a bookstore application
class out_of_stock : public std::runtime_error
{
public:
    explicit out_of_stock(const std::string &s) : std::runtime_error(s) {}
};

class isbn_mismatch : public std::logic_error
{
public:
    explicit isbn_mismatch(const std::string &s) : std::logic_error(s) {}
    isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs) : std::logic_error(s), left(lhs), right(rhs) {}
    const std::string left, right;
};

class Base
{
public:
    virtual double f1(double) noexcept; // doesn't throw
    virtual int f2() noexcept(false);   // can throw
    virtual void f3();                  // can throw
};

class Derived : public Base
{
public:
    // double f1(double);        // error: Base::f1 promises not to throw
    double f1(double) noexcept;
    int f2() noexcept(false); // ok: same specification as Base::f2
    void f3() noexcept;       // ok: Derived f3 is more restrictive
};

void recoup(int i) noexcept
{
    cout << i << endl;
}

void f(int)
{
    int i = 12 / 0;
}

void e() noexcept(noexcept(f(0)))
{
    recoup(2);
    f(0);
}

int main(int argc, char const *argv[])
{
    /* code */
    if (noexcept(recoup(0)))
    {
        cout << "recoup will not throw" << endl;
    }

    if (noexcept(e()))
    {
        cout << "e will not throw" << endl;
    }

    // both recoup and pf1 promise not to throw
    void (*pf1)(int) noexcept = recoup;
    // ok: recoup won't throw; it doesn't matter that pf2 might
    void (*pf2)(int) = recoup;
    // pf1 = f; // error: alloc might throw but pf1 said it wouldn't
    pf2 = f; // ok: both pf2 and alloc might throw

    return 0;
}

