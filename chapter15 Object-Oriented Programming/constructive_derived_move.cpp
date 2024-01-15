#include <iostream>
#include <string>

/*
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
 * In this case, the corresponding copy verison constructor will be called.
 * 
 * That why the move operation has undefined status but the copy operation has not!!!
 */

/*
 * Look the following code, if the move constructor is explicitly declared as delete,
 * the class will can not be copy initialized from rvalue.
 */
class Base
{
public:
    Base() = default;
    Base(Base &&) = delete;
    Base(const Base &)
    {
        std::cout << "Base copy constructor" << std::endl;
    }
    std::string name;
};

class Derived : public Base
{
public:
    Derived() = default;
    Derived(Derived &&) = default;
    Derived(const Derived &)
    {
        std::cout << "Derived copy constructor" << std::endl;
    }
};

class Foo
{
public:
    ~Foo() {};
    Foo(const Foo &)
    {
        std::cout << "Foo copy constructor" << std::endl;
    }
    Foo() = default;
    // Foo(Foo &&) = delete;
};

int main(int argc, char const *argv[])
{
    Base b;
    Base b3 = b;    // ok
    // the Base(b) is a rvalue
    // Base b2 = Base(b); // error C2280: 'Base::Base(Base &&)': attempting to reference a deleted function
    // Base b2(b);

    Derived d;
    Derived d2 = Derived(d);
    Derived d3(std::move(d2));  // ok: actually call the Derived's copy constructor

    Foo f;
    // For gcc, the copy elision is mandatory, and the move operation will be ommitted.
    // But for msvs, this is an error, because the copy elision is not mandatory, 
    // so the correpsonding copy or move constructor must not be deleted.
    // For move constructor, the implicitly-declared or defaulted deleted move constructor
    // will be undefined, so they will be ignored when executing overload resolution.
    Foo f2 = Foo();
    return 0;
}
