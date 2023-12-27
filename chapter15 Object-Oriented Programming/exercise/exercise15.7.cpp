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

  private:
    std::string bookNo;

  protected:
    double price = 0.0;
};

// ==================================================
// 				Normal Discount Class
// ==================================================

class Bulk_quote : public Quote {
  public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &b, double p, std::size_t n, double disc)
        : Quote(b, p), min_qty(n), discount(disc){};
    double net_price(std::size_t n) const override {
        return n < min_qty ? n * price : n * price * (1 - discount);
    }

  protected:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

// ============================================
//          Limited Discount Class
// ============================================

class Limited_quote : public Bulk_quote {
  public:
    Limited_quote() = default;
    Limited_quote(const std::string &b, double p, std::size_t n, double disc)
        : Bulk_quote(b, p, n, disc) {}
    double net_price(std::size_t cnt) const override {
        return cnt < min_qty
                   ? cnt * price
                   : min_qty * price * (1 - discount) + (cnt - min_qty) * price;
    }
};

// print_total
std::ostream &print_total(std::ostream &os, const Quote &quo, size_t cnt) {
    return os << quo.isbn() << " : " << quo.net_price(cnt);
}

int main(int argc, char const *argv[]) {
    Quote q1("b1", 34.2);
    Bulk_quote q2("b1", 34.2, 20, 0.1);
    Limited_quote q3("b1", 34.2, 20, 0.1);

    print_total(std::cout, q1, 30) << std::endl;
    print_total(std::cout, q2, 30) << std::endl;
    print_total(std::cout, q3, 30) << std::endl;

    return 0;
}
