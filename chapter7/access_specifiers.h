#include <iostream>
#include <string>

#ifndef ACCESS_SPECIFIERS_H
#define ACCESS_SPECIFIERS_H
/*
 * public: are accessible to all parts of the program.
 *
 * private: are accessible to member functions of the class
 * 
 * There are no restrictions on how often an access specifier may appear.
 * 
 * The only difference between struct and class is the default access level. If we use
 * the struct keyword, the members defined before the first access specifier are public;
 * if we use class, then the members are private.
 * 
 * As a matter of programming style, when we define a class intending for all of its
 * members to be public, we use struct. If we intend to have private members, the we use class.
 * 
 * 
 * Friends
 * 
 * A class can allow another class or function to access its nonpublic members by making that
 * class or function a friend.
 * 
 * 
 * Encapsulation
 * 
 * By defining data members as private, the class author is free to make changes in the data. Another
 * advantage of making data members private is that the data are protected from mistakes that users
 * might introduce. If there is a bug that corrupts an object's state, the place to look for
 * the bug are localized: Only code that is part of the implementation could be responsible for the error.
 * 
 * Although user code need not change when a class definition changes, the source files that use a class
 * must be recompiled any time the class changes.
 */

class Sales_data {
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &, std::string end);
    friend std::istream &read(std::istream &, Sales_data &);

  public:
    // Sales_data() = default;
    // Sales_data(const std::string &s) : bookNo(s) {}
    
    // defines the default constructor as well as one that takes a string argument
    explicit Sales_data(std::string s = "") : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(const std::string &s, unsigned n);
    Sales_data(int i, std::istream &is = std::cin) : Sales_data(is) {}
    explicit Sales_data(std::istream &is) {
        std::istream &read(std::istream &, Sales_data &);
        read(is, *this);
    }
    // other members as before
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

  private:
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0; // this is called `in-class initializer`
    double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &, std::string end = "");
std::istream &read(std::istream &, Sales_data &);

#endif