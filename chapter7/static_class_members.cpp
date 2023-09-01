#include <iostream>

/*
 *
 * Just like the static member in python or java. What needs to note is that
 * static member functions do not have a `this` pointer, so they may not be
 * declared as const.
 * 
 * When we define a static member outside the class, the keyword appears only with
 * the declaration inside the class body. We must define and initialize each 
 * static data member outside the class body. Like any other object, a static data member
 * may be defined only once. The definition of static member function, like any other
 * member definition, has access to the private members of the class.
 * 
 * 
 * In-Class Initialization of static Data members
 * 
 * We can provide in-class initializers for static members that have const
 * integral type and must do so for static members that are constexprs of
 * literal type. The initializers must be constant expressions. Such members
 * are themselves constant expressions.
 * 
 * If an initializer is provided inside the class, the member's definition must not
 * specify an initial value.
 * 
 * Even if a const static data is initialized in the class body, that member ordinarily
 * should be defined outside the class definition.
 * 
 * If the member is used only in contexts where the compiler can substitute the member's value,
 * then an initialized const or constexpr static need not be separately defined. However, if
 * we use the member in a context in which the value cannot be substitued, then there must
 * be a definition for that member. For example, if we pass Account::period to a function that
 * takes a int & (but not const int &), then period must be defined.
 * 
 * 
 * static Members Can Be Used in Ways Ordinary Members Can't
 * 
 * A static data member can have incomplete type. In particular, a staitc data member
 * can have the same type as the class type of which it is a member. Another difference
 * between static and ordinary members is that we can use a static member as a default
 * argument.
 */

class Accout {
  public:
    static double rate() { return interestRate; }
    static void rate(double);
  private:
    // in-class initializer for static member data
    static constexpr int period = 30;
    double daily_tbl[period];
    static double interestRate;
};
// ordinarily, class static members must be initialized outside the class body
double Accout::interestRate = 3.0;

// definition of a static member with no initializer
constexpr int Accout::period;   // initializer provided in the class definition

void Accout::rate(double d) {
    ;
}


class Bar {
  public:
  private:
    static Bar mem1;    // ok, static member can have incomplete type
};


class Screen {
  public:
    Screen &clear2(char = bkground);
    Screen &clear(char = bkground) { std::cout << bkground << std::endl; return *this; }
  private:
    static const char bkground;
};

const char Screen::bkground = 97;

int main(int argc, char const *argv[])
{
    Screen s;
    s.clear();
    /* code */
    return 0;
}
