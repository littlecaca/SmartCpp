#include <iostream>
#include <string>

class Book {
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

