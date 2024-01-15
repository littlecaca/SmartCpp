#include <string>
#include "access_specifiers.h"
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/*
 * Implicit Class-Type Conversions
 * 
 * Every constructor that can be called with a single argument defines an implicit
 * conversion to a class type. Such constructors are sometimes referred to as converting
 * constructors.
 * 
 * 
 * Only One Class-Type Conversion Is Allowed
 * 
 * 
 * Suppressing Implicit Conversions Defined by Constructors
 * 
 * We can prevent the use of a constructor in a context that requires an implicit
 * conversion by declaring the constructor as explicit.
 * 
 * `explicit` Constructors Can Be Used Only for Direct Initialization
 */

int main(int argc, char const *argv[])
{
    string null_book = "9-999";
    Sales_data s1("9-999", 12, 33.3);
    
    

    // the null_book is implicitly converted to Sales_data type
    // s1.combine(null_book);
    // like
    // s1.combine(Sales_data("9-999"))

    print(cout, s1) << endl;
    


    Sales_data s2 = Sales_data("9-999");
    int i = int();  // value initailization
    cout << i << endl;

    // explicit using constructors for conversions
    s1.combine(Sales_data(cin));
    // or using the static_cast to indicate the istream constructor
    s1.combine(static_cast<Sales_data>(cin));

    return 0;
}
