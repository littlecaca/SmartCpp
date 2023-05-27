#include "adt.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
 * The fundamental ideas behind classes are data abstraction and encapsulation.
 * Data abstraction is a programing (and design) technique that relies on the
 * separation of interface and implementation. The interface of a class consists
 * of the operations that users of the class can execute. The implementation
 * includes the class's data members, the bodies of the functions that
 * constitute the interface, and any functions needed to define the class that
 * are not intended for general use.
 *
 *
 * A well-designed class has an interface that is intuitive and easy to use and
 * has an implementation that is efficient enough for its intended use.
 *
 *
 * Defining Class
 *
 * Member functions must be declared inside the class. Member functions may be
 * defined inside the class itself or outside the class body. Nonmember
 * functions that are part of the interface are declared and defined outside the
 * class.
 *
 * Functions defined in the class are implicitly inline.
 *
 *
 * Introducing `this`
 *
 * Member functions access the object on which the were called through an extra,
 * implicit parameter named `this`. When we call a member function, `this` is
 * initialized with the address of the object on which the function was invoked.
 *
 * Inside a member function, we can refer directly to the members of the object
 * on which the function was called. Any direct use of a member of the class is
 * assumed to be an implicit reference through `this`. `this` is a const
 * pointer.
 *
 *
 * `const` Member Functions
 *
 * By default, the type of `this` in a Sales_data member function is `Sales_data
 * *const`, but we can add `const` following the parameter list to declare it as
 * `const Sales_data * const`.
 *
 * Objects that are const, and references or pointers to const objects, may call
 * only `const` member functions.
 *
 *
 * Class Scope and Member Functions
 *
 *
 * Defining a Member Function outside The Class
 *
 * As with any other function, when we define a member function outside the
 * class body, the member's definition must match its declaration.
 * 
 * 
 * Defining Nonmember Class-Related Functions
 * 
 * Class authors often define auxiliary functions, such as our add, read, and print functions.
 * Although they are conceptually part of the interface of the class, they are not part of the
 * class itself. Ordinarily, nonmember functions that are part of the interface of a class
 * should be declared in the same header as the class itself.
 * 
 * 
 * Copy, Assignment, and Destruction
 * 
 * Although the compiler will synthesize the copy, assignment, and destruction operation
 * for us, for some classes the default version do not work correctly. In particular, the 
 * synthesized versions are unlikely to work correctly for classes tht allocate resources
 * that reside outside the class objects themselves.
 */

// return the average price
double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

// defining a function to return "this" object
Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// the IO classes are types that cannot be copied, so we may only pass them
// by reference. Moreover, reading or writing to a stream changes that stream, so
// both functions take ordinary references, not references to const
std::istream &read(std::istream &is, Sales_data &i1) {
    std::cout << "Please input bookno, revenue, units_sold:" << std::endl;
    std::cin >> i1.bookNo >> i1.revenue >> i1.units_sold;
    return is;
}

// the print function does not print newline, the function that do output should
// do minimal formatting. That way user code can decide whether the newline is needed
std::ostream &print(std::ostream &os, Sales_data const &i1) {
    double price = i1.units_sold == 0 ? 0 : i1.revenue / i1.units_sold;
    std::cout << "(" << i1.bookNo << ", "
              << i1.revenue << ", " << i1.units_sold
              << ")";
    std::cout << " price = " << price;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}