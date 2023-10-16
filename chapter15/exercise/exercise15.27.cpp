#include <string>
#include <iostream>

inline void print(const std::string &s) {
    std::cout << s << std::endl;
}

class Quote {
public:
    // Default Constructor
    Quote() : price(0.), bookNo("") {
        print("Quote()");
    }
    // Copy Constructor
    Quote(const Quote &base) : price(base.price), bookNo(base.bookNo) {
        print("Quote(const Quote &)");
    }
    // Move Constructor
    Quote(Quote &&base) : price(std::move(base.price)), bookNo(std::move(base.bookNo)) {
        print("Quote(Quote &&)");
    }
    // Copy Assignment
    Quote &operator=(const Quote &base) noexcept {
        price = base.price;
        bookNo = base.bookNo;
        print("Quote *operator(const Quote &)");

        return *this;
    }
    // Move Assignemnt
    Quote &operator=(Quote &&base) noexcept {
        price = base.price;
        bookNo = std::move(base.bookNo);
        print("Quote *operator(Quote &&)");

        return *this;
    }
    // Destructor
    ~Quote() { print("~Quote"); }
protected:
    double price;
private:
    std::string bookNo;
};


class Bulk_quote : public Quote {
public:
    using Quote::Quote;
};

