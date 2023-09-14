#include <algorithm>
#include <iostream>
#include <string>

class Book {
    friend std::ostream &operator<<(std::ostream &os, const Book &b);
    friend std::istream &operator>>(std::istream &os, Book &b);
    friend bool operator==(const Book &b1, const Book &b2);

  public:
    Book(const std::string &book_isbn, const std::string &book_name,
         double book_price, unsigned book_count)
        : isbn(book_isbn), name(book_name), price(book_price),
          count(book_count) {}
    Book(const std::string &book_isbn, const std::string &book_name,
         double book_price)
        : Book(book_isbn, book_name, book_price, 0) {}
    // default constructor
    Book() : Book("", "", 0, 0.0) {}

    Book &operator+=(const Book &);

    // Copy assignment operator
    // If we define one move operation, the all synthesized copy operations
    // will be deleted.
    Book &operator=(const Book &) = default;

    // Copy constructor
    Book(const Book &) = default;

    // Move assignment operator
    Book &operator=(Book &&) = default;

    // Move constructor
    Book(Book &&) = default;


  private:
    std::string isbn;
    std::string name;
    double price;
    unsigned count;
};

// Input operator
std::istream &operator>>(std::istream &is, Book &b) {
    is >> b.isbn >> b.name >> b.price >> b.count;

    if (std::find(b.isbn.begin(), b.isbn.end(), '-') == b.isbn.end())
        is.setstate(is.rdstate() | is.failbit);

    if (!is)
        b = Book();
    return is;
}

// Output operator
std::ostream &operator<<(std::ostream &os, const Book &b) {
    os << "(" << b.isbn << ", " << b.name << ", " << b.price << ", " << b.count
       << ")";
    return os;
}

// Compound assignment for addition
Book &Book::operator+=(const Book &b) {
    if (isbn != b.isbn)
        std::cout << "Inconsistent ISBN number" << std::endl;
    else {
        if (count + b.count != 0)
            price = (price * count + b.price * count) / (count + b.count);
        else
            price = (price + b.price) / 2;
        count += b.count;
    }
    return *this;
}

// Addition operator
Book operator+(const Book &b1, const Book &b2) {
    Book sum = b1;
    sum += b2;
    return sum;
}

// Compare operator
inline bool operator==(const Book &b1, const Book &b2) {
    return b1.isbn == b2.isbn && b1.name == b2.name && b1.count == b2.count &&
           b1.price == b2.price;
}

// Inequality Operator
inline bool operator!=(const Book &lhs, const Book &rhs) {
    return !(lhs == rhs);
}

// Move constructor


int main(int argc, char const *argv[]) {
    Book b("12-32", "The empire's death", 123, 21);
    Book b2 = std::move(b);
    std::cout << b2 << std::endl;
    return 0;
}
