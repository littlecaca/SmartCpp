#include <iostream>
#include <string>

namespace Exe {

class Quote {
  public:
	Quote() = default;
	Quote(const std::string &book, double sales_price)
		: bookNo(book), price(sales_price) {}
	std::string isbn() const { return bookNo; }
	std::ostream &print_total(std::ostream &os, std::size_t n) const {
		return (os << net_price(n));
	}
	virtual double net_price(std::size_t n) const { return n * price; }
	// Virtual destructors are needed even if they do no work
	virtual ~Quote() = default;

  private:
	std::string bookNo;

  protected:
	double price = 0.0;
};

class Bulk_quote : public Quote {
  public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &b, double p, std::size_t n, double disc)
    	: Quote(b, p), min_qty(n), discount(disc) {};
    double net_price(std::size_t n) const override {
		return n < min_qty ? Quote::net_price(n) : Quote::net_price(n) * discount;
	}

  private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

// Test whether the derived class can directly access the base'base class.
class DD : public Bulk_quote {
public:
    void test() {
        Quote::net_price(2);
    }
};

} // namespace Exe
