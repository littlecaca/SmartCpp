#include <string>
#include <iostream>
// #include "adt.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
 * Constructors
 * 
 * Classes control object initialization by defining one or more special member
 * funcitons known as constructors.
 * 
 * Constructors have the same name as the class. Unlike other functions, constructors
 * have no return type. Constructors can write to const objects during their construction.
 * 
 * 
 * The Synthesized Default Constructor
 * 
 * If our class doesn's explicitly define any construtors, the compiler will implicitly
 * define the default constructor for us which is known as the synthesized default constructor.
 * For most classes, this synthesized constructor initializes each data member of the class
 * as follows:
 * 1. If there is an in-class initializer, use it to initailze the member.
 * 2. Otherwise, default-initialize the member.
 * 
 * Some Classes Cannot Rely on the Synthesized Default Constructor
 * 
 * First, the compiler generates a default constructor automatically only if a class declares
 * no constructors, so me may need to define our own default constructor is we have other constructors.
 * 
 * Second, classes that have members of built-in or compound type usually should rely on
 * the synthesized default constructor only if all such members have in-class initializers.
 * 
 * Third, sometimes the compiler is unable to synthesize one.
 */


// defining a constructor outside the class body

class Sales_data {
  public:
    Sales_data () {}
    Sales_data (double p) {}
    string bookNo = "you are";
    double revenue = 4.6;
    int units_sold = 7;
};

std::ostream &print(std::ostream &os, Sales_data const &i1) {
    double price = i1.units_sold == 0 ? 0 : i1.revenue / i1.units_sold;
    std::cout << "(" << i1.bookNo << ", "
              << i1.revenue << ", " << i1.units_sold
              << ")";
    std::cout << " price = " << price;
    return os;
}

int main(int argc, char const *argv[])
{
    Sales_data s1;
    Sales_data s3(5.5);

    print(cout, s1) << endl;
    print(cout, s3) << endl;
    return 0;
}
