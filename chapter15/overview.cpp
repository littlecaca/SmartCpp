#include <string>
#include <iostream>

/*
 * Object-Oriented Programing
 *
 * Object-oriented programing is based on three fundamental concepts:
 * data abstraction, inheritance, and dynamic binding.
 * 
 * Base class
 * Derived classes
 * 
 * In C++, a base class distinguishes functions that are type dependent
 * from those that it expects its derived classes to inherit without change.
 * The base class defines as virtual those functions it expects its derived
 * classes to define for themselves.
 * 
 * Note
 * In C++, dynamic binding happens when a virtual function is called
 * through a reference(or a pointer) to a base class. 
 */

class Quote {
  public:
    std::string isbn() const;
    virtual double net_price(std::size_t n) const;
  private:
    int num;
};

class Bilk_quote : public Quote {
  public:
    double net_price(std::size_t) const override;
    void test() {
		
    }
};