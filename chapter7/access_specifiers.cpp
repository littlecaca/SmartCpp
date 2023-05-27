#include <iostream>
#include <string>

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
 */
class Sales_data {
  public:
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p * n) {}

    Sales_data(std::istream &is) {
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