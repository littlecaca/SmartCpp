#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;

/*
 * Unlike other classes, classes that are literal types may have function
 * members that are `constexpr`. (These member functions are implicitly
 * const.)[this does not mean you can omit the const keyword]
 *
 * In addition to the arithmetic types, references, and pointers, certain
 * classes are also literal types.
 *
 * An aggregate class whose data members are all of literal type is a literal
 * class. A nonaggrate class, that meets the following restrictions, is also a
 * literal class.
 *      1. The data member all must have literal type.
 *      2. The class must have at least one constexpr constuctor.
 *      3. If a data member has an in-class initializer, the initializer for a
 *         member of built-in type must be a constant expression, or if the member has
 *         class type, the initializer must use the member's own constexpr constructor.
 * 		     [A constexpr constructor must initialize every data member. The
 *         initializers must either use a constexpr constructor (constructor list
 *         initializer) or be a constant expression (in-class initializer).]
 *      4. The class must use default definition for its destructor.
 *
 * constexpr class can not call non-constexpr constructor
 *
 * constexpr Constructors
 *
 * A constexpr constructor can be declared as = default (or as deleted
 * function). Otherwise, a constexpr constructor must meet the requirements of a
 * constructor--meaning it can have no return statement--and of a constexpr
 * function--meaning the only executable statement it can have is a return
 * statement. As a result, the body of a constexpr constructor is typically
 * empty.
 * 
 * From C++14, the body of constexpr function can have local variable and loop statements.
 */

// an example of literal class
class Debug {
  public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
    constexpr bool any() const {
        return hw || io || other;
    } 
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { other = b; }

  private:
    bool hw;
    bool io;
    bool other;
};

// this is also a literal class, because
class Debug2 {
  public:
    Debug2() = default; // "= default" is a constexpr constructor
    Debug2(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
    bool any() const { return hw || io || other; }
    bool hw = false;
    bool io = false;
    bool other = false;
};

// this is not a literal class, because it has not constexpr constructor
class Debug3 {
  public:
    Debug3() {}
    bool hw = false;
    bool io = false;
    bool other = false;
};

// this is not a literal class, because `hw` has not initializer, it makes
// the default constructor not a constexpr constructor
class Debug4 {
  public:
    Debug4() = default;
    bool hw;
    bool io = false;
    bool other = false;
};

int main(int argc, char const *argv[]) {
    constexpr Debug io_sub(false, true, false);
    if (io_sub.any()) {
        cerr << "error" << endl;
    }

    const Debug2 d2(false, false,
                    false); // ok, and d2 don't need to be a literal class
    // constexpr Debug2 d3(false, false, false);	// error: cannot call
    // non-constexpr function
    constexpr Debug2 d3;
    // constexpr Debug3 d4;		// error: a constexpr variable must have a literal
    // type or a reference type constexpr Debug4 d5;		// error:
    // initialization is not constant

    if (!d2.any()) {
        cerr << "error" << endl;
    }
    
    return 0;
}
