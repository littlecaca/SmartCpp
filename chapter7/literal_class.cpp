#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

/*
 * Unlike other classes, classes that are literal types may have function members
 * that are `constexpr`. (These member functions are implicitly const.)[this is not true!]
 * 
 * In addition to the arithmetic types, references, and pointers, certain classes are 
 * also literal types.
 * 
 * An aggregate class whose data members are all of literal type is a literal class.
 * A nonaggrate class, that meets the following restrictions, is also a literal class.
 *      1. The data member all must have literal type.
 *      2. The class must have at least one constexpr constuctor.
 *      3. If a data member has an in-class initializer, the initializer for a member of
 *         built-in type must be a constant expression, or if the member has class type,
 *         the initializer must use the member's own constexpr constructor.
 *      4. The class must use default definition for its destructor.
 * 
 * 
 * constexpr Constructors
 * 
 * A constexpr constructor can be declared as = default (or as deleted function). Otherwise,
 * a constexpr constructor must meet the requirements of a constructor--meaning it can have
 * no return statement--and of a constexpr function--meaning the only executable statement it
 * can have is a return statement. As a result, the body of a constexpr constructor is typically empty.
 */


// an example of literal class
class Debug {
  public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
    constexpr bool any() const { return hw || io || other; }  // this memner function is implicitly const
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { other = b; }
  private:
    bool hw;
    bool io;
    bool other;
};

int main(int argc, char const *argv[])
{
    constexpr Debug io_sub(false, true, false);
    if (io_sub.any()) {
        cerr << "error" << endl;
    }
    return 0;
}
