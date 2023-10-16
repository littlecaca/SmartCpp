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
    // Default Constructor
    Bulk_quote() : Quote(), discount(0.0) {
        print("Bulk_quote()");
    }
    // Copy Constructor
    Bulk_quote(const Bulk_quote &bulk) : Quote(bulk), discount(bulk.discount) {
        print("Bulk_quote(const Bulk_quote &)");
    }
    // Move Constructor
    Bulk_quote(Bulk_quote &&bulk) : Quote(std::move(bulk)), discount(std::move(bulk.discount)) {
        print("Bulk_quote(Bulk_quote &&)");
    }
    // Copy Assignment
    Bulk_quote &operator=(const Bulk_quote &bulk) noexcept {
        Quote::operator=(bulk);
        discount = bulk.discount;
        print("Bulk_quote &operator=(const Bulk_quote &)");
        
        return *this;
    }
    // Move Assignment
    Bulk_quote &operator=(Bulk_quote &&bulk) noexcept {
        Quote::operator=(std::move(bulk));
        discount = std::move(bulk.discount);
        print("Bulk_quote &operator=(Bulk_quote &&)");

        return *this;
    }
    // Destructor
    ~Bulk_quote() {
        print("~Bulk_quote()");
    }
private:
    double discount;
}; 

int main(int argc, char const *argv[])
{
    Bulk_quote bulk;
    Bulk_quote bulk2(bulk);
    return 0;
}
