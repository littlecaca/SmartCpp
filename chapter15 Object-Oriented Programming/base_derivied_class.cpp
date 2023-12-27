#include <iostream>
#include <string>

/*
 * Note
 * Base classes ordinarily should define a virtual destructor.
 * Virtual destructors are needed even if they do no work.
 *
 *
 *
 * Member Functions and Inheritance
 *
 * Any nonstatic member function, other than a constructor, may be
 * virtual. A function that is declared as virtual in the base class
 * is implicitly virtual in the derived classes as well.
 *
 * Access Control and Inheritance
 *
 * When the derivation is public, the public members of the base class
 * become part of the interface of the derived class as well. In
 * addition, we can bind an object of a publicly derived type to a pointer
 * or reference to the base type.
 *
 * Virtual Functions in the Derived Class
 *
 * If a derived class does not override a virtual from its base, then, like
 * any other member, the derived class inherits the version defiend in the
 * base class.
 *
 * Derived-Class Objects and the Derived-to-Base Conversion
 *
 * A derived object contains multiple parts: a subobjects containing the
 * (nonstatic) members defined in the derived class itself, plus subobejcts
 * corresponding to each base class from which the derived class inherits.
 *
 * Derived-Class Constructors
 *
 * As with a data member, unless we say otherwise, the base part of a derived
 * object is default initialized.
 *
 * Note
 * The base class is initialized first, and then the members of the derived
 * class are initialized in the order in which they are declared in the class.
 *
 * Key Concept: Respecting the Base-Class Interface
 *
 * Interactions with an object of a class-type should use the interface
 * of that class. even if that object is the base-class part of a derived
 * obejct.
 *
 * Inheritance and static Members
 *
 * Declarations of Derived Classes
 *
 * The declaration contains the class name but does not include its derivation
 * list. The derivation list, and all other details of the definition, must
 * appear together in the class body.
 *
 * Classes Used as a Base Class
 *
 * A class must be defined, not just declared, before we can use it as a base
 * class. A base class can itself be a derived class.
 *
 * Preventing Inheritance
 *
 * Under the new standard, we can prevent a class from being used as a base
 * by following the class name with final.
 *
 * 
 * 
 * Conversions and Inheritance
 * 
 * Note
 * Like built-in pointers, the smart pointer classes support the derived-to-base
 * conversion--we can store a pointer to a derived object in a smart pointer
 * to the base type.
 * 
 * Static Type and Dynamic Type
 * 
 * The static type of an expression is always known at compile time--
 * it is the type with which a variable is declared or that an expression
 * yields. The dynamic type is the type of the obejct in memory that
 * the variable or expression represents.
 * The dynamic type may not be known until run time.
 * 
 * The dynamic type of an expression that is neither a reference nor
 * a pointer is always the same as that expression's static type.
 * 
 * Note
 * It is crucial to understand that the static type of a pointer or
 * reference to a base class may differ from its dynamic type.
 * 
 * There Is No Implicit Conversion from Base to Derived
 * 
 * If the base class has one or more virtual functions, we can use a
 * dynamic_cast to request a conversion that is checked at run time.
 * Alternatively, in those cases when we know that the conversion from
 * base to derived is safe, we can use a static_cast to override the compiler.
 * 
 * ...and No Conversion between Objects
 * 
 * Because the copy-control members take references, the derived_to_base
 * conversion lets us pass a derived object to a base_class copy/move operation.
 * 
 * Bulk_quote bulk;
 * Quote item(bulk);
 * item = bulk;
 * 
 * Because the Bulk_quote part is ignored, we say that the Bulk_quote portion of
 * bulk is sliced down.
 * 
 */

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
// 				Defining a Derived Class
// ==================================================

class Bulk_quote : public Quote {
  public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &b, double p, std::size_t n, double disc)
    	: Quote(b, p), min_qty(n), discount(disc) {};
    double net_price(std::size_t n) const override {
		return n < min_qty ? net_price(n) : net_price(n) * discount;
	}

  private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};


// =========================================
//        Preventing Inheritance
// =========================================

class NoDerived final {};
class Base {};
class Last final : Base {};
