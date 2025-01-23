#include <iostream>

/*
 * Name Lookup Happens at Compile Time
 *
 * 
 * 
 * Name Collisions and Inheritance
 * 
 * As usual, names definedn in an inner scope hide uses of that name
 * in the outer scope.
 * 
 * 
 * 
 * Using the Scope Operator to Use Hidden Members
 * 
 * struct Derived : Base {
 *      int get_base_mem() { return Base::mem; }
 * }
 * 
 * Best Pratices
 * Aside from overriding inerited virtual functions, a derived class usually
 * should not reuse names defined in its base class.
 * 
 * 
 * 
 * As Usual, Name Lookup Happens before Type Checking
 * 
 * 
 * 
 * Virtual Functions and Scope
 * 
 * 
 * 
 * Calling a Hidden Virtual Through the Base Class
 * 
 * 
 * 
 * Overriding Overloaded Functions
 * 
 * A derived class can override zero or more instances of the overloaded
 * functions it inherits. If a derived class wants to make all the overloaded
 * versions avaiable through its type, then it must override all of them or none
 * or them.
 * 
 * A using declaration for a base-class member function adds all the overloaded
 * instances of that function to the scope of the derived class.
 * 
 * The access to the overloaded versions that are not otherwise redefined by
 * the derived class will be the access in effect at the point of the using
 * declaration.
 * 
 */

class Base {
public:
    virtual void f() { std::cout << "Base f()" << std::endl; };
    void f(int) { std::cout << "Base f(int)" << std::endl; }
    void f(int, int) { std::cout << "Base f(int, int)" << std::endl; }
    void lala() {}
};

class Derived : public Base {
public:
    // int f() override {};
    using Base::f;
    void f() override { std::cout << "Derived f()" << std::endl; }
    void lala() {}
};

int main(int argc, char const *argv[])
{
  Derived d;
  d.f();
  d.f(1, 1);
  return 0;
}
