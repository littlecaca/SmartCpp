/*
 * protected Members
 *
 * A derived class member or friend may access the protected members if the
 * base class only through a derived obejct. The derived class has no special
 * access to the protected members of base-class objects.
 * 
 * Access to a member that a class inherits is controlled by a combination of
 * the access specifier for that member in the base class, and the access specifier
 * in the derivation list of the derived class.
 * 
 * Access to the members of a base class is controlled by the access specifiers
 * in the base class itself. 
 * 
 * The purpose of the derivation access specifier is to control the access that
 * users of the derived class--including other classes derived from the derived class
 * --have to the members inherited from Base.
 * 
 * When the inheritance is public, members retain their access specification.
 * 
 * 
 * 
 * Accessibility of Derived-to-Base Conversion
 * 
 * Assuming D inherits from B:
 * 1.User code may use the derived-to-base conversion only if D inherits
 * publicly from B.
 * 2.Member functions and friends of D can use the conversion to B regardless of
 * how D inherits from B.
 * 3.Member functions and friends of classes derived from D may use the derived-to-base
 * conversion if D inherits from B using either public or protected.
 * 
 * 
 * 
 * Key Concept: Class Design and protected Members
 * 
 * An implementation member should be protected if it provides an operation
 * or data that a derived class will need to use in its own implementation.
 * Otherwise, implementation members should be private.
 * 
 * 
 * 
 * Friendship and Inheritance
 * 
 * Friendship is not inherited.
 * 
 * 
 * 
 * Exempting Individual Members
 * 
 * We can change the access level of a name that a derived class inherits by
 * providing a using declaration.
 * 
 * 
 * 
 * Default Inheritance Protection Levels
 * 
 * By default, a derived class defined with the class keyword has private
 * inheritance; a derived class defined with the struct keyword has public
 * inheritance.
 * 
 * The only differences between class and struct keyword are the default access
 * specifier for members and the default derivation access specifier.
 */

#include <iostream>

class Base {
    friend class Pal;
  public:
    int public_mem;
    int f();
  protected:
    Base() : prot_mem(12) {}
    int prot_mem;
  private:
    int priv_mem;
};

class Sneaky : public Base {
  protected:
    int sneaky_mem;
};

class Pal {
  public:
    int f(Base b) { return b.priv_mem; }
    // int f2(Sneaky s) { return s.sneaky_mem; }   // error

    // This may be suprising, Attention!:
    int f3(Sneaky s) { return s.priv_mem; }     // ok, because Pal is Base's friend
};

class Derived : private Base {
  public:
    using Base::public_mem;
    using Base::f;
    using Base::prot_mem;
  protected:

};

int main(int argc, char const *argv[])
{
  Derived d;
  std::cout << d.prot_mem << std::endl;
  return 0;
}
