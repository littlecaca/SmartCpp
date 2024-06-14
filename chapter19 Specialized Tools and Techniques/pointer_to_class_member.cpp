#include <functional>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

/**
 * Pointer to Class Member
 *
 * The type of a pointer to member embodies both the type of a class and the type of
 * a member of that class.
 *
 *
 * Pointers to Data Members
 *
 * As with any pointer, we declare a pointer to member using a * to indicate that the
 * name we’re declaring is a pointer. Unlike ordinary pointers, a pointer to member also
 * incorporates the class that contains the member. Hence, we must precede the * with
 * classname:: to indicate that the pointer we are defining can point to a member of
 * classname.
 *
 *
 * Using a Pointer to Data Member
 *
 * It is essential to understand that when we initialize or assign a pointer to member,
 * that pointer does not yet point to any data. We supply the object when we dereference the
 * pointer to member.
 *
 *
 * A Function Returning a Pointer to Data Member
 *
 *
 * Pointers to Member Functions
 *
 * As with normal function pointers, if the member is overloaded, we must distinguish
 * which function we want by declaring the type explicitly (§ 6.7, p. 248).
 *
 * Unlike ordinary function pointers, there is no automatic conversion between a
 * member function and a pointer to that member.
 *
 *
 * Using a Pointer to Member Function
 *
 * As when we use a pointer to a data member, we use the .* or ->* operators to call
 * a member function through a pointer to member.
 *
 * Note
 * Because of the relative precedence of the call operator, declarations of
 * pointers to member functions and calls through such pointers must use
 * parentheses: (C::*p)(parms) and (obj.*p)(args).
 *
 *
 * Using Type Aliases for Member Pointers
 *
 * Note
 * Type aliases make code that uses pointers to members much easier to read
 * and write.
 *
 *
 * Pointer-to-Member Function Tables
 *
 *
 * 
 * Using Member Functions as Callable Objects
 * 
 * Unlike ordinary function pointers, a pointer to member is not a callable object; 
 * these pointers do not support the function-call operator. 
 * 
 * 
 * Using function to Generate a Callable
 * 
 * One way to obtain a callable from a pointer to member function is by using the library
 * function template.
 * 
 * Ordinarily, the object on which a member function executes is
 * passed to the implicit this parameter. When we want to use function to generate
 * a callable for a member function, we have to “translate” the code to make that implicit
 * parameter explicit.
 * 
 * When the callable is a member function, the signature’s first parameter 
 * must represent the (normally implicit) object on which the member will be run. 
 * 
 * The signature we give to function must specify whether the object will be passed 
 * as a pointer or a reference.
 * 
 * 
 * Using mem_fn to Generate a Callable
 * 
 * We can, instead, let the compiler deduce the member’s type by using another library
 * facility, mem_fn, which, like function, is defined in the functional header.
 * 
 * 
 * Using bind to Generate a Callable
 * 
 * Like mem_fn, the first argument to the callable generated by bind can
 * be either a pointer or a reference to a string.
 * 
 */

class Screen
{
public:
    typedef std::string::size_type pos;
    using Action =
        char (Screen::*)(pos, pos) const;
    char get_cursor() const { return contents[cursor]; }
    char get() const;
    char get(pos ht, pos wd) const;
    static const std::string Screen::*data()
    {
        return &Screen::contents;
    }
    static const pos Screen::*cur()
    {
        return &Screen::cursor;
    }

private:
    std::string contents;
    pos cursor;
    pos height, width;
};

Screen &action(Screen &, Screen::Action = &Screen::get);

/**
 * Implement the member function table
 */
class Extended : public Screen
{
public:
    using Activity = Screen &(Extended::*)();
    Screen &home();
    Screen &forward();
    Screen &back();
    Screen &up();
    Screen &down();
    enum Directions
    {
        HOME,
        FORWARD,
        BACK,
        UP,
        DOWN
    };
    Screen &move(Directions dir)
    {
        return (this->*Menu[dir])();
    }

private:
    static Activity Menu[];
};

Extended::Activity Extended::Menu[] = {
    &Extended::home,
    &Extended::forward,
    &Extended::back,
    &Extended::up,
    &Extended::down
};

int main(int argc, char const *argv[])
{

    /**
     * Declares that pdata is a “pointer to a member of class Screen
     * that has type const string.”
     */
    const std::string Screen::*pdata;
    pdata = Screen::data();

    Screen myScreen, *pScreen = &myScreen;

    auto s = myScreen.*pdata;
    s = pScreen->*pdata;

    const Screen::pos Screen::*cur = Screen::cur();
    auto cursor = myScreen.*cur;

    /**
     * The easiest way to form a pointer to member function is to
     * use auto to deduce the type for us
     */
    auto pmf = &Screen::get_cursor;

    char (Screen::*pmf2)() const = &Screen::get_cursor;
    // using a pointer to a member function
    auto c2 = (myScreen.*pmf2)();
    auto c3 = (pScreen->*pmf2)();


    auto fp = &std::string::empty;
    std::vector<std::string> vs;
    // The pointer to member function is not callable
    // std::find_if(vs.begin(), vs.end(), fp);

    std::function<bool(const std::string &)> fcn = &std::string::empty;
    std::find_if(vs.begin(), vs.end(), fcn);

    /**
     * Had our vector held pointers to string, we would have told function to
     * expect a pointer
     */
    std::vector<std::string *> vs2;
    std::function<bool(const std::string *)> fcn2 = &std::string::empty;
    std::find_if(vs2.begin(), vs2.end(), fcn2);

    // Using mem_fn to Generate a Callable
    // Utilizing the call operator function overloading
    std::find_if(vs.begin(), vs.end(), std::mem_fn(&std::string::empty));
    std::find_if(vs2.begin(), vs2.end(), std::mem_fn(&std::string::empty));

    auto it = std::find_if(vs.begin(), vs.end(), 
        std::bind(&std::string::empty, std::placeholders::_1));
    return 0;
}

/**
 * Without the parentheses, the compiler treats the following as an (invalid)
 * function declaration.
 */
char Screen::*p();