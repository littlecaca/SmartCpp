#include <memory>
#include <string>

/**
 * Multiple and Virtual Inheritance
 *
 *
 * Multiple inheritance is the ability to derive a class from more than one direct base
 * class (§ 15.2.2, p. 600). A multiply derived class inherits the properties of all its
 * parents.
 *
 *
 * Multiple Inheritance
 *
 * As with single inheritance, the derivation list may include only classes that have
 * been defined and that were not defined as final. A base class may appear only once
 * in a given derivation list.
 *
 *
 * Multiply Derived Classes Inherit State from Each Base Class
 *
 * Under multiple inheritance, an object of a derived class contains a subobject for each
 * of its base classes (§ 15.2.2, p. 597).
 *
 *
 * Derived Constructors Initialize All Base Classes
 *
 * The order in which base classes are constructed depends on the order in which they
 * appear in the class derivation list. The order in which they appear in the constructor
 * initializer list is irrelevant.
 *
 *
 * Inherited Constructors and Multiple Inheritance
 *
 * Under the new standard, a derived class can inherit its constructors from one or more
 * of its base classes (§ 15.7.4, p. 628). It is an error to inherit the same constructor
 * (i.e., one with the same parameter list) from more than one base class.
 *
 *
 * Destructors and Multiple Inheritance
 * 
 * Destructors are always invoked in the reverse order from which the constructors are
 * run. In our example, the order in which the destructors are called is ~Panda,
 * ~Endangered, ~Bear, ~ZooAnimal.
 * 
 * 
 * Copy and Move Operations for Multiply Derived Classes
 * 
 * 
 * Conversions and Multiple Base Classes
 * 
 * A pointer or reference to any of an object’s (accessible) base classes can be used 
 * to point or refer to a derived object.
 * 
 * The compiler makes no attempt to distinguish between base classes in terms of a
 * derived-class conversion. Converting to each base class is equally good.
 * 
 * void print(const Bear&);
 * void print(const Endangered&);
 * 
 * an unqualified call to print with a Panda object would be a compile-time error.
 * 
 * 
 * Lookup Based on Type of Pointer or Reference
 * 
 * 
 * Class Scope under Multiple Inheritance
 * 
 * Under multiple inheritance, this same lookup happens simultaneously among all the
 * direct base classes. If a name is found through more than one base class, then use of
 * that name is ambiguous.
 * 
 * It is perfectly legal for a class to inherit multiple members with the same
 * name. However, if we want to use that name, we must specify which version we want
 * to use.
 * 
 * As always, name lookup happens before type checking (§ 6.4.1, p. 234). When the
 * compiler finds max_weight in two different scopes, it generates an error noting that
 * the call is ambiguous.
 * 
 * The best way to avoid potential ambiguities is to define a version of the function in
 * the derived class that resolves the ambiguity. 
 * 
 * 
 */

class ZooAnimal
{
};

class Endangered
{
public:
    static Endangered critical;
};

class Bear : public ZooAnimal
{
public:
    Bear() = default;
    Bear(const std::string &, bool, const std::string &);
};

class Panda : public Bear, public Endangered
{
public:
    Panda(std::string, bool);
    Panda();
};

// explicitly initialize both base classes
Panda::Panda(std::string name, bool onExhibit)
    : Bear(name, onExhibit, "Panda"), Endangered(Endangered::critical) {}
// implicitly uses the Bear default constructor to initialize the Bear subobject
Panda::Panda()
    : Endangered(Endangered::critical) {}

struct Base1
{
    Base1() = default;
    Base1(const std::string &);
    Base1(std::shared_ptr<int>);
};
struct Base2
{
    Base2() = default;
    Base2(const std::string &);
    Base2(int);
};

// error: D1 attempts to inherit D1::D1 (const string&) from both base classes
struct D1 : public Base1, public Base2
{
    using Base1::Base1; // inherit constructors from Base1
    using Base2::Base2; // inherit constructors from Base2

    
};

struct D2 : public Base1, public Base2
{
    /* data */
    using Base1::Base1;
    using Base2::Base2;

    // D2 must define e its own constructor that takes a string
    D2(const std::string &s): Base1(s), Base2(s) {}
    // needed once D2 defines its own constructor
    D2() = default;
};


int main(int argc, char const *argv[])
{
    // D1 d1("sda");   // call to constructor of 'D1' is ambiguous
    return 0;
}

class BB
{
protected:
    void f() {}
};

class DD : private BB
{
public:
    void v()
    {
        (*this).f();
        f();
    }
};

void test()
{
    DD d;
}


int x = 11;
class Base
{
public:
    int x = 12;
};

namespace A
{

int x = 10;
class Derived : Base
{
public:
    void f()
    {
        x;
    }
};
}


class F1
{
public:
    void f(int) {}
};

class F2
{
public:
    void f() {}

};

class C : public F1, public F2
{
public:
    /**
     * the f() in the base classes will lead to name lookup error in compile time
     * if we use f() in the derived class.
     * So we need to define a version of the function in the derived class 
     * that resolves the ambiguity.
    */
    // void f()
    // {
    //     F1::f(12);
    //     F2::f();
    // }
    void ff()
    {
        // f();
    }
};

void test2()
{
    C c;
    
}