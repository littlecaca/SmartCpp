#include <string>
#include <iostream>

/*
 * 看似有很多例外，实际内部有很强的一致性
 *
 * Virtual Destructors
 * 
 * Warning
 * Executing `delete` on a pointer to base that points to the derived class
 * has undefined behaviour if the base's destructor is not virtual.
 * 
 * 
 * Virtual Destructors Turn Off the Synthesized Move
 * 
 * 
 * 
 * Synthesized Copy Control and Inheritance
 * 
 * The synthesized copy-control members in a base or a derived class execute like any
 * other synthesized constructor, assignment operator, or destructor: They memberwise
 * initialize, assign, or destroy the members of the class itself. In addition, these
 * synthesized members initialize, assign, or destroy the direct base part of an object by
 * using the corresponding operation from the base class.
 * 
 * All that matters is that the corresponding member in the base class is accessible 
 * and that it is not a deleted function.
 * 
 * 
 * 
 * Base classes and Deleted Copy Control in the Derived
 * 
 * 1.If the default construcor, copy constructor, copy assignment operator, or
 * destructor in the base class is deleted or inaccessible, then the corresponding
 * member in the derived class is defined as deleted.
 * 
 * 2.If the base class has an inaccessible or deleted destructor, then the synthesized
 * default and copy constructors in the derived classes are defined as deleted,
 * because there is no way to destroy the base part of the derived object.
 * 
 * 3.As usual, the compiler will not synthesize a deleted move operation. If we use
 * = default to request a move operation, it will be a deleted function in the derived
 * if the corresponding operation in the base is deleted or inaccessible.
 * The move constructor will also be deleted if the base class destrucor 
 * is deleted or inaccessible.
 * 
 * 
 * 
 * Move Operations and Inheritance
 * 
 * Because lack of a move operation in a base class suppresses synthesized move for
 * its derived classes, base classes ordinaribly should define the move operations
 * if it is sensible to do so.
 * 
 * Question:
 * Why does compiler generates move constructor despite base class being non-move-constructible?
 * Answer:
 * A defaulted move constructor that is defined as deleted is ignored by overload resolution.
 * (otherwise it would prevent copy-initialization from rvalue).
 * 
 * 
 * 
 * 
 * Derived-Class Copy-Control Members
 * 
 * Unlike the constructors and assignment operators, the destructor is responsible
 * only for destroying the resources allocated by the derived
 * 
 * Warning
 * When a derived class defines a copy or move operation, that operation is responsible
 * for copying or moving the entire object, including base-class members.
 * 
 * Defining a Derived Copy or Move Constructor
 * 
 * If the initializer for the base class is ommitted, the Base default constructor
 * would be used to initializee the base part of a D object.
 * So if we want copy (or move) the base-class part, we must explicitly use the copy
 * (or move) constructor for the base class in the derived's constructor initializer list.
 * 
 * 
 * Derived-Class Assignment Operator
 * 
 * Like the copy and move constructors, a derived-class assignemnt operator must assign
 * its base part explicitly.
 * 
 * Derived-Class Destructor
 * 
 * Unlike the constructors and assignment operators, a derived destructor 
 * is responsible only for destroying the resources allocated by the
 * derived class.
 * 
 * 
 * 
 * Calls to Virtuals in Constructors and Destructors
 * 
 * The Order of Construction and Destruction
 * 
 * The base-class part of a derived object is constructed first. While the
 * base-class constructor is executing, the derived part of the object is uninitialized.
 * Similarly, derived objects are destroyed in reverse order, so that when a base class
 * destructor runs, the derived part has already been destroyed.
 * 
 * While these base-class members are executing, the object is incomplete.
 * To accommodate this incompleteness, the compiler treats the object as if its type
 * changes during construction or destruction. That is, while an object is being
 * constructed it is treated as if it has the same class as the constructor; calls to virtual
 * functions will be bound as if the object has the same type as the constructor itself.
 * Similarly, for destructors. This binding applies to virtuals called directly or that are
 * called indirectly from a function that the constructor (or destructor) calls.
 * 
 * 
 * 
 * Inherited Constructors
 * 
 * Under the new standard, a derived class can reuse the constructors defined by its direct
 * base class. Although, such constructors are not inherited in the normal sense of that term, 
 * it is common to refer to such constructors as "inherited". A class cannot inherit the default,
 * copy, and move constructors.
 * 
 * A derived class inherits its base-class constructors by providing a using declaration
 * 
 * Ordinarily, a `using` declaration only makes a name visible in the current scope. When applied
 * to a constructor, a using declaration causes the compiler to generate code.
 * 
 * These compiler-generated constructors have the form
 *      derived(parms) : base(args) {}
 * If the derived class has any data members of its own, those members are default initialized.
 * 
 * 
 * Characteristics of an Inherited Constructor
 * 
 * Unlike using declarations for ordinary members, a constructor using declaration does not change
 * the access level of the inherited constructors.
 * 
 * Moreover, a using declaration can't specify explicit or constexpr. If a constructor in the base
 * is explicit or constexpr, the inherited constructor has the same property.
 * 
 * If a base-class constructor has default arguments, those arguments are not inherited. Instead, the
 * derived class gets multiple inherited constructors in which each parameter with a default argument
 * is successively omitted.
 * 
 * If a base class has several constructors, then with two exceptions, the derived class inherits each
 * of the constructors from its base class.. The first exception is that a
 * derived class can inherit some constructors and define its own versions of other
 * constructors. If the derived class defines a constructor with the same parameters as a
 * constructor in the base, then that constructor is not inherited. The one defined in the
 * derived class is used in place of the inherited constructor.
 * The second exception is that the default, copy, and move constructors are not
 * inherited. These constructors are synthesized using the normal rules. An inherited
 * constructor is not treated as a user-defined constructor. Therefore, a class that
 * contains only inherited constructors will have a synthesized default constructor.
 * 
 */

class Base {
public:
    ~Base() = delete;
    std::string name = "sa";
};

class Derived2 : public Base {
public:
    double price;
};


class B {
public:
    B() {};
    B(const B&) = delete;

};

class D : public B {

};

class B2 {
public:
    B2(B2 &&) {
        std::cout << "Move Operation" << std::endl;
    };
    B2() = default;
    B2(const B2 &) = default;
    B2 &operator=(const B2 &) = default;
    virtual ~B2() {};
};

class Quote {
public:
    Quote() = default;              // memberwise default initialize
    Quote(const Quote&) = default;  // memberwise copy
    Quote(Quote &&) = default;      // memberwise copy
    Quote &operator=(const Quote&) = default;   // copy assign
    Quote &operator=(Quote &&) = default;       // move assign
    virtual ~Quote() = default;
};

class Derived : public Quote {
public:
    Derived() = default;
    // Derived(const Derived &) = default;
    // Derived(Derived &&) = default;
};


class D2 : public B2 {
public:
    D2() = default;

};


class B3 {
public:
    B3(int) {}
};

class D3 : public B3 {
public:
    // D3() {
    //     B3::B3(2);
    // }

    // Must be this form
    D3() : B3(2) {

    }
};


// Calls to Virtuals in Constructors and Destructors
class B4 {
public:
    virtual void out() { 
        std::cout << "B4 out()" << std::endl; 
    }
    // this->out() will be bound as if the *this is B4
    B4() { 
        auto p = this;
        p->out(); func(); 
    }
    
    // normal bound
    void func() { 
        auto p = this;
        p->out(); 
    }
};

class D4 : public B4 {
public:
    virtual void out() override { std::cout << "D4 out()" << std::endl; }
    void test() { func(); }
};

class B5 {
public:
    B5() {}
    B5(int) {}
};

class D5 : public B5 {
public:
    using B5::B5;
};

int main(int argc, char const *argv[])
{
    Base *b = new Base();

    // the default constructor of "Derived" cannot be referenced -- it is a deleted function
    // Derived d;
    std::cout << b->name << std::endl;

    D d;
    // D d2{d};    // error
    // D d3{std::move(d)}; // error

    B2 b2;
    B2 b3(b2);
    // b3 = b2;

    Derived d2;
    Derived d3{d2};

    D2 dd;
    D2 dd2(std::move(dd));

    D4 d4;
    d4.func();

    D5 d5;

    Quote q1;
    Quote q2(q1);

    return 0;
}
