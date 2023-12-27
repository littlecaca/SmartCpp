#include <iostream>


/*
 * Virtual Function
 * 
 * Unlike the ordinary functions, we must define every virtual function,
 * regardless of whether it is used, because the compiler has no way to
 * determine whether a virtual function is used.
 * 
 * 
 * 
 * Key Concept: Conversions among Types Related by Inheritance
 * 
 * 1.The conversion from derived to base applies only to pointer or reference types.
 * 2.There is no implicit conversion from the base-class type to the derived type.
 * 3.Like any member, the derived-to-base conversion may be inaccessible due to
 *   access controls.
 * 
 * 
 * 
 * Calls to Virtual Functions May Be Resolved at Run Time
 * 
 * When a virtual function is called through a reference or pointer, the compiler
 * generates code to decide at run time which function to call.
 * 
 * When we call a virtual function on an expression that has a plain--nonreference
 * and nonpointer--type, that call is bound at compile time.
 * 
 * 
 * 
 * Virtual Functions in a Derived Class
 * 
 * A derived-class function that overrides an inherited virtual function must have
 * exactly the same parameter type(s) as the base-class function that it overrides.
 * 
 * With one exception, the return type of a virtual in the derived class also
 * must match the return type of the function from the base class. The exception
 * applies to virtuals that return a reference (or pointer) to types that are
 * themselves related by inheritance. That is, if D is derived from B, then a base
 * class virtual can return a B* and the version in the derived can return a D*.
 * However, such return types require that the derived-to-base conversion from D to
 * B is accessible.
 * 
 * 
 * 
 * The final and override Specifiers
 * 
 * Under the new standard we can specify override on a virtual function in a derived
 * class. Doing so makes our intention clear and (more importantly) enlists the compier
 * in finding such problems for us.
 * 
 * We can also designate a function as final. Any attempt to override a function
 * that has been defined as final will be flagged as an error.
 * 
 * final and override specifiers appear after the parameter list (including any const
 * or reference qualifiers) and after a trailing return.
 * 
 * 
 * 
 * Virtual Functions and Default Arguments
 * 
 * Like any other function, a virtual function can have default arguments. If
 * a call uses a default argument, the value that is used is the one defined by 
 * the static type through which the function is called.
 * 
 * Best Pratices
 * Virtual functions that have default arguments should use the same argument
 * values in the base and derived classes.
 * 
 * 
 * 
 * Circumventing the Virtual Mechanism
 * 
 * double discounted = baseP->Quote::net_price(42);
 * This call will be resolved at compile time.
 * 
 * Warning
 * If a derived virtual function that intended to call its base-class version
 * omits the scope operator, the call will be resolved at run time as a call
 * to the derived version itself, resulting in an infinite recursion.
 * 
 * 
 */


class Base {
  public:
    virtual void print() {
        std::cout << "I am from Base class" << std::endl;
    }
};

class Derived : public Base {

};

void print_m(Base &b) {
    b.print();
}

// Circumventing the Virtual Mechanism
void test(Base &b) {
    // calls the version from the base class
    b.Base::print();
}

int main(int argc, char const *argv[])
{
    Derived d;
    print_m(d);
    return 0;
}
