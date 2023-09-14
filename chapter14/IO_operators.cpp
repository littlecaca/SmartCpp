#include <iostream>

/*
 * Overloading the Output Operator <<
 * 
 * Overloading the Input Operator >>
 * 
 * Note
 * Input operators must deal with the possibility that the input might fail;
 * output operatoes generally don't bother.
 * 
 * std::cin >> price;
 * 
 * If any of the read operations fails, price will have an undefined value.
 * 
 * 
 * 
 * Best Pratices
 * Input operators should decide what, if anythingm to do about error recovery.
 *
 * 
 * 
 * Indicating Errors
 * 
 * Usually an input operator should set only the failbit. eofbit and badbit are
 * best left to the IO library itself to indicate. 
 */

#include <iostream>
#include <string>

class Book {
    friend std::ostream &operator<<(std::ostream &os, const Book &b);
    friend std::istream &operator>>(std::istream &is, Book &b);
  public:
    Book(const std::string &book_isbn, const std::string &book_name, double book_price,
         unsigned book_count) : isbn(book_isbn), name(book_name),
         price(book_price), count(book_count) {}
    Book(const std::string &book_isbn, const std::string &book_name, double book_price) :
         Book(book_isbn, book_name, book_price, 0) {}
    // default constructor
    Book() : Book("", "", 0, 0.0) {}
  private:
    std::string isbn;
    std::string name;
    double price;
    unsigned count;
};

// Input operator
std::istream &operator>>(std::istream &is, Book &b) {
    is >> b.isbn >> b.name >> b.price >> b.count;
    // If get wrong input set failbit to is
    if (b.isbn.size() > 100) 
        is.setstate(is.rdstate() | std::istream::failbit);
    // If fails to read, retuan a default initialized Book
    if (!is)
        b = Book();
     
    return is;
}

// Output operator
std::ostream &operator<<(std::ostream &os, const Book &b) {
    os << "(" << b.isbn << ", " << b.name << ", "
       << b.price << ", " << b.count << ")";
    return os;
}

// Addition operator
Book operator+(const Book &b1, const Book &b2);

// Compare operator
bool operator==(const Book &b1, const Book &b2);

int main(int argc, char const *argv[])
{
    Book b("12-32", "The empire's death", 123, 21);
    std::cout << b << std::endl;
    return 0;
}
