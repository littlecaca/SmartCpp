#include <iostream>
#include <string>

#ifndef ADT_H
#define ADT_H

struct Sales_data {
    /*
     * constructors added
     */

    // what = default means

    // first, note that this constructor defines the default constructor because
    // it takes no arguments. the = default can appear with the declaration
    // inside the class body or on the definition oustside the class body. Like
    // any other function, if the = default appears inside the class body, the
    // defualt constructor will be inlined. Sales_data() = default;
    Sales_data() {
        units_sold = 0;
        revenue = 0.0;
    }

    // constructor initializer list

    // the constructor initializer is a list of member names, each of which is
    // followed by that member's initial value in parentheses (or inside curly
    // braces). Multiple member initializations are seperated by commas. when a
    // member is ommited from the constructor list, it is implicitly initialized
    // using the same process as is used by the synthesized default constructor.
    // If you can't use in-class initializers, each constructor should
    // explicitly initialize every member of built-in type.
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p * n) {}

    // even though the constructor initializer list is empty, the members of
    // this object are still initialized before the constructor body is
    // executed.
    Sales_data(std::istream &is) {
        std::istream &read(std::istream &, Sales_data &);
        read(is, *this);
    }
    // other members as before
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0; // this is called `in-class initializer`
    double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &, const string &end = "");
std::istream &read(std::istream &, Sales_data &);


// return the average price
inline double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

#endif