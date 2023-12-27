#include <string>
#include <iostream>

// =========================================
//          Defining a Base Class
// =========================================

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

// ==================================================
// 				Defining a Derived Class
// ==================================================

class Bulk_quote : public Quote {
  public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &b, double p, std::size_t n, double disc)
    	: Quote(b, p), min_qty(n), discount(disc) {};
    double net_price(std::size_t n) const override {
		return n < min_qty ? n * price : n * price * (1 - discount);
	}

  private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};


// print_total
std::ostream &print_total(std::ostream &os, const Quote &quo, size_t cnt) {
    return os << quo.isbn() << " : " << quo.net_price(cnt);
}

int main(int argc, char const *argv[])
{
    Quote q1("b1", 34.2);
    Bulk_quote q2("b1", 34.2, 20, 0.1);

    print_total(std::cout, q1, 30) << std::endl;
    print_total(std::cout, q2, 30) << std::endl;
    
    return 0;
}
