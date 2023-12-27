#include <iostream>
#include <string>

class Sales_data {
  public:
	// other members and constructors as before
	// declaration equivalent to the synthesized copy constructor
	Sales_data(const Sales_data &);
	Sales_data(const std::string &bn, int us = 0, double re = 0.)
		: bookNo(bn), units_sold(us), revenue(re) {}

	// Conversion operation
	explicit operator std::string() const { return bookNo; }
	explicit operator double() const { return revenue; }

  private:
	std::string bookNo;
	int units_sold;
	double revenue;
};

// The synthesized copy constructor for Sales_data is equivalent to:
Sales_data::Sales_data(const Sales_data &orig)
	: bookNo(orig.bookNo), units_sold(orig.units_sold), revenue(orig.revenue) {}

int main(int argc, char const *argv[]) {
	// DemoConstMember d1;
	// std::cout << d1.x << std::endl;
	// std::cout << d1.y << std::endl;
	// PrivateCopy c;
	// c.test();

	Sales_data s1("you", 4, 9.2);
    // std::cout << static_cast<std::string>(s1) << std::endl;
    std::cout << static_cast<double>(s1) << std::endl;
    std::cout << std::string{std::string("sad")} << std::endl;
    
	return 0;
}
