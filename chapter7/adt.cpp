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
 */

struct Sales_data {
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

