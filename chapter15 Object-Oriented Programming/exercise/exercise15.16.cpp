#include <iostream>
#include <string>

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
    virtual std::ostream &debug(std::ostream &os) {
        os << "bookNo: " << bookNo << ", price: " << price;
        return os;
    }

  private:
    std::string bookNo;

  protected:
    double price = 0.0;
};

// ==================================================
//              Defining a ABC
// ==================================================

class Disc_quote : public Quote {
  public:
    Disc_quote() = default;
    Disc_quote(const std::string &b, double p, std::size_t n, double disc)
        : Quote(b, p), min_qty(n), discount(disc){};
    virtual double net_price(std::size_t) = 0;
  protected:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

// ==================================================
// 				Defining a Derived Class
// ==================================================

class Bulk_quote : public Disc_quote {
  public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &b, double p, std::size_t n, double disc)
        : Disc_quote(b, p, n, disc) {}
    double net_price(std::size_t n) const override {
        return n < min_qty ? net_price(n) : net_price(n) * discount;
    }
    std::ostream &debug(std::ostream &os) override {
        this->Quote::debug(os)
            << ", min_qty: " << min_qty << ", discount: " << discount;
    }
};

int main(int argc, char const *argv[]) { return 0; }
