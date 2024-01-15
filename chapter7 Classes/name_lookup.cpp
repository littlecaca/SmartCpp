#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/*
 * Name Lookup and Class Scope
 *
 * Member function definitions are processed after the compiler processes all of the declarations
 * in the class.
 * 
 * The two-step process applies only to names used in the body of a member function.
 * 
 * 
 * Type Name Are Special
 * 
 * Ordinarily, an inner scope can redefine a name from an outer scope even if that name has already
 * been used in the inner scope. However, in a class, if a member uses a name from an outer scope and
 * that name is a type, then the class may not subsequently redefine that name.
 * 
 * 
 * Even though the class member is hidden, it is still possible to use that member by qualifying the
 * member's name with the name of its class or by using the `this` pointer explicitly.
 * 
 * If we want the name from the outer scope, we can ask for it explicitly using the scope operator.
 */


typedef double Money;
string bal;
// typedef int Money;   // error: conflicting declaration ‘typedef int Money’

class Account {
  public:
    Money balance() { return bal; }
  private:
    // typedef double Money;   // error: declaration of ‘typedef double Account::Money’ changes meaning of ‘Money’

    // overload the bal from the outer scope
    Money bal;
};

int main(int argc, char const *argv[])
{
    Money m  = 0.0;
    typedef int Money;
    
    /* code */
    return 0;
}

