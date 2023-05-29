#include <iostream>

/*
 * When a constructor delegates to another constructor, the constructor initializer list
 * and function body of the delegated-to constructors are both executed.
 */

class Sales_data {
    friend std::istream &read(std::istream &, Sales_data &);
  public:
    Sales_data(std::string s, unsigned cnt, double price) :
        bookNo(s), units_sold(cnt), revenue(price) {
            std::cout << "called Sales_data(s, cnt, price)"
                      << std::endl;
        }
    Sales_data() : Sales_data("", 0, 0) {
        std::cout << "called Sales_data()" << std::endl;
    }
    Sales_data(std::string s) : Sales_data(s, 0, 0) {
        std::cout << "called Sales_data(s)" << std::endl;
    }
    Sales_data(std::istream &is) : Sales_data() { 
        read(is, *this);
        std::cout << "called Sales_data(is)" << std::endl;
    }
  private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream &read(std::istream &, Sales_data &);


int main(int argc, char const *argv[])
{
    Sales_data d1(std::cin);
    return 0;
}

