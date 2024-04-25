#include <iostream>
#include <string>

/*
 * A class controls what happens when objects of that class
 * are copied, moved, assigned, and destroyed, and it does this
 * by five special member functions: copy constructor, copy-assignment
 * operator, move constructor, move-assignment operator, and destructor.
 * Collectively, we'll refer to these operations as copy control.
 *
 * If a class does not define all of the copy-control members, the
 * compiler automatically defines the missing operations.
 *
 *
 *
 * The Copy Constructor
 *
 * A constructor is the copy constructor if its first parameter
 * is a reference to the class type and any additional parameters
 * have default values.
 *
 *
 * The synthesized Copy Constructor
 *
 * The systhesized copy constructor for some classes prevents us from
 * copying objects of that class type. Otherwise, the synthesized copy
 * constructor memberwise copies the members of its argument into the
 * object being created.
 *
 * Members of class type are copied by the copy constructor for that class;
 * members of built-in type are copied directly.
 *
 *
 * Copy Initialization
 *
 * Copy initialization ordinarily uses the copy constructor.
 * When copy initialization happens and that copy initialization
 * requires either the copy constructor or the move constructor.
 *
 * Copy initialization happens not only when we define variables using an =,
 * but also when we:
 *      (This is why the copy constructor's own parameter must be a reference.)
 *      Pass an object as an argument to a parameter of nonreference type.
 *      Return an object from a function that has a nonreference return type.
 *      Brace initialize the elements in an array or the members of an aggregate
 * class.
 *
 *
 * Constraints on Copy Initialization
 *
 * Whether we use copy or direct initialization matters if we use an
 * initializer that requires conversion by an explicit constructor.
 *
 *
 * The Compiler Can Bypass the Copy Constructor
 *
 * The compiler is permitted to rewrite
 *      string null_book = "9-999-99999-9";   ( -> converting construct -> copy
 * construct) into string null_book("9-999-99999-9");    ( -> converting
 * construct)
 *
 * Remember that the compiler can omit calls to the copy constructor.
 * (Because the converting constructors can unilaterally construct it.)
 * However, even if the compiler omits the call to the copy/move constructor.
 * the copy/move constructor must exist and must be accessible(e.g., not
 * private) at that point at the program.
 *
 *
 *
 * The Copy-Assignment Operator
 *
 * Intorducing Overloaded Assignment
 *
 * Some operators, assignment among them, must be defined as member functions.
 * When an operator is a member function, the left-hand operand is bound to the
 * implicit `this` parameter. The right-hand operand in a binary operator,
 * such as assignment, is passed as an explict parameter.
 *
 * The copy-assignment operator takes an argument of the same type as the class.
 * Like assignment for built-in types, assignment operators ordinarily should
 * return a reference to their left-hand operand.
 *
 * The Synthesized Copy-Assignment Operator Is just like the Copy-Constructor.
 *
 *
 *
 * The Destructor
 *
 * The destructor is a member function with the name of the class prefixed by
 * a tilde(~). It has no return value and takes no parameters.
 *
 * Unlike the constructor, the function body of the destructor is executed first
 * and then the members are destroyed. Members are destroyed in reverse order
 * from the order in which they were initialized.
 *
 * The built-in types do not have destructors, so nothing is done to destory
 * members of built-in type.
 *
 * When a Destructor Is Called
 *
 * 1.Variables are destroyed when they go out of scope.
 * 2.Members of an obejct are destroyed when the object of which they are a part
 * is destroyed.
 * 3.Elements in a container--whether a library or an array--are destroyed when
 * the container is destroyed.
 * 4.Dynamically allocated obejcts are destroyed when the delete operator is
 * applied to a pointer to the obejct. 5.Temporary objects are destroyed at the
 * end of the full expression in which the temporary was created.
 *
 * Note:
 * The destructor is not run when a reference or a pointer to an object goes out
 * of scope.
 *
 * The Synthesized Desturctor
 *
 * The synthesized desructor of some classes disallows objects of the type to be
 * destroyed. Otherwise, the synthesized destructor has an empty function body.
 * The members are automatically destroyed after the (empty) destructor body is
 * run. A destructor body executes in addition to the memberwise destruction
 * that takes place as part of destroying an obejct.
 *
 *
 *
 * The Rule of Three/Five
 *
 * In general, it is unusual to need one without needing to define them all.
 *
 * Classes That Need Destructors Need Copy and Assignement
 *
 * Classes That Need Copy Need Assignment, and Vice Versa
 *
 * Some classes have work that needs to be done to copy or assign objects but
 * has no need for the destructor.
 *
 *
 *
 * Using = default
 *
 * We can explicitly ask the compiler to generate the synthesized versions of
 * the copy-control members by defining them as = default.
 *
 * Note:
 * We can use = default only on member functions that have a synthesized
 * version.
 *
 *
 *
 * Preventing Copies
 *
 * Under the new standard, we can prevent copies by defining the copy
 * constructor and copy-assignment operator as deleted functions. A deleted
 * function is one that is declared but may not be used in any other way.
 *
 * Unlike = default, = delete must appears on the first declaration of a deleted
 * function. Also unlike = default, we can specify = delete on any function.
 *
 * The Destructor Should Not be a Deleted Member
 *
 * If the destructor is deleted, the compiler will not let us define variables
 * or create temporaries of a type that has a deleted destructor.
 *
 * Although we cannot define variables or members that have a deleted
 * destructor, we can dynamically allocate obejcts with a deleted destructor.
 * However, we cannot free them. (using allocator class)
 *
 * The Copy-Control Members May Be Synthesized as Deleted
 *
 * 1.The synthesized destructor is defined as deleted if the class has a member
 * whose own destructor is deleted or is inaccessible (e.g. private)
 *
 * 2.So does the synthesized copy constructor. It is also deleted if the class
 * has a member with a deleted or inaccessible destructor.
 *
 * 3.So does the copy-assignment, and so also does it if the class has a const
 * or reference member. （If the copy-assignemnt operator were synthesized
 * for such classes, the left-hand oeprand would continue to refer to
 * the same object as it did before the assignment. It would not refer to
 * the same object as the right-hand operand. This behavior is unlikely to be
 * desired.)
 *
 * 4.So does the synthesized default constructor. If the class has a member
 * with a deleted or inaccessible destructor or has a reference
 * that does not have an in-class initializer; or has a const member whose 
 * type does not explicitly define a default constructor and that member does
 * not have an in-class initializer.
 *
 *
 * 
 * private Copy Control
 *
 * To prevent copies by friends and members, we declare these members as private
 * but do not define them. An attempt to use an undefined member results in a
 * link-time failure.
 *
 *
 */

class Sales_data {
  public:
    // other members and constructors as before
    // declaration equivalent to the synthesized copy constructor
    Sales_data(const Sales_data &);

  private:
    std::string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};

// The synthesized copy constructor for Sales_data is equivalent to:
Sales_data::Sales_data(const Sales_data &orig)
    : bookNo(orig.bookNo), units_sold(orig.units_sold), revenue(orig.revenue) {}

class Foo {
  public:
    // no work to do other than destroying the members, which happens
    // automatically
    ~Foo() {} // destructor
};

// Explicitly specify = default
class Demo {
  public:
    Demo() = default;
    Demo(const Demo &) = default;
    Demo &operator=(const Demo &);
    ~Demo() = default;
};
// Don't want the copy-assignment oeprator to be inline.
Demo &Demo::operator=(const Demo &) = default;

class DemoDeleted {
  public:
    DemoDeleted() = default;
    // Prevent the Copy-Constructor or Copy-Assignment
    DemoDeleted(const DemoDeleted &) = delete;
    DemoDeleted &operator=(const DemoDeleted &) = delete;
};

class DemoConstMember {
  public:
    DemoConstMember() : x(3) {}
    const int x;
    const int y = 2;
};

class PrivateCopy {
    PrivateCopy(const PrivateCopy &);
    PrivateCopy &operator=(const PrivateCopy &);

  public:
    PrivateCopy() = default;
    void test();
};

void test();

class Test {
	int i;
  public:
	Test(int n) : i(n) {
		std::cout << "Test(int n)" << std::endl;
	}
	Test(Test &t) : i(t.i) {
		std::cout << "Test(Test &t)" << std::endl;
	}
	// Test(Test &t) = delete;
};

int main(int argc, char const *argv[]) {
    // DemoConstMember d1;
    // std::cout << d1.x << std::endl;
    // std::cout << d1.y << std::endl;
    // PrivateCopy c;
    // c.test();

	// ok
	  Test t1 = 3;
	

    return 0;
}
