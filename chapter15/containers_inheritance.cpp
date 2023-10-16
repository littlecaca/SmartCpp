#include <set>
#include <memory>
#include <iostream>
#include <string>
#include <initializer_list>


/*
 * Warning
 * Because derived objects are "slice down" when assined to a base-type
 * object, containers and types relatrd by inheritance do not mix well.
 *
 * Put (Smart) Pointers, Not Objects, in Containers
 *
 * We can convert a smart pointer to a derived type to a smart pointer to an
 * base-class type.
 *
 *
 *
 * Simulating Virtual Copy
 *
 * Sometimes, we need to copy an object pointed (or referenced) by a pointer (or referrence),
 * but we don't know the real type of the object, so we probably can't copy initialize a object
 * with the totally same type with the original obejct.
 *
 * To solve this problem, we can give the class of the original object a virtual member
 * that allocates a copy of itself.
 *
 * 
 */

class Quote;
class Bulk_quote;


class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price)
        : bookNo(book), price(sales_price) {}

    // Allocates a copy of itself
    virtual Quote *clone() const &
    {
        return new Quote(*this);
    }

    virtual Quote *clone() &&
    {
        return new Quote(std::move(*this));
    }

    std::string isbn() const { return bookNo; }
    std::ostream &print_total(std::ostream &os, std::size_t n) const
    {
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

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &b, double p, std::size_t n, double disc)
        : Quote(b, p), min_qty(n), discount(disc){};

    // Allocates a copy itself
    Bulk_quote *clone() const & override
    {
        return new Bulk_quote(*this);
    }

    Bulk_quote *clone() && override
    {
        return new Bulk_quote(std::move(*this));
    }
    
    double net_price(std::size_t n) const override
    {
        return n < min_qty ? Quote::net_price(n) : Quote::net_price(n) * discount;
    }

private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};


class Basket
{
public:
    void add_item(const Quote &sale)
    {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    void add_item(Quote &&sale) {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }

    double total_receipt(std::ostream &) const;

private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs) { return lhs->isbn() < rhs->isbn(); }

    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};