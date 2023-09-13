#include <iostream>

/*
 * Note
 * Member operator functions have one less(explicit) parameter
 * than the number of operands.
 *
 * An operator must either be a member of a class or have at least one
 * parameter of class type.
 *
 * We cannot change the meaning of an operator when applied to operands
 * of built-in type.
 *
 *
 *
 * Operators That Cannot Be Overloaded
 *
 * ::
 *
 * .*
 *
 * .
 *
 * ?:
 *
 *
 * For symbols serve as both unary and binary operators,
 * the number of parameters determines which operator is being defined.
 * 
 * 
 * 
 * Best Pratices
 * 
 * Ordinarily, the comma, address-of, logical AND, and logical OR operators
 * should not be overloaded.
 * 
 * 
 * 
 * Use Definitions Thar Are Consistent with the Built-in Meaning
 * 
 * Most common, but still inadvisable, are uses that contort an operator's
 * "normal" meaning to force a fit to a given type.
 * 
 * 
 * 
 * Choosing Member or Nonmember Implementation
 * 
 * 1. =, [], (), -> must be defined as members
 * 2. compound-assignment operators ought to be members
 * 3. Operators that change the state of their object or that are closely
 *    tied to their given type--such as increment, decrement, dereference
 * 4. symmetric operators which might convert either operand--such as
 * the arithmetic, equality, relational, and bitwise operators--usually
 * should be defined as ordinary nonmember functions.
 * 
 * 
 * When we define an operator as a member function, then the left-hand
 * operand must be an object of the class of which that operator is a member.
 * 
 * 
 * For nonmember operator functions, the only requirements are that at
 * least one of the operands has a class type, and that both operands
 * can be converted (unambiguously) to string.
 * 
 * 
 * 
 */

class Int {
  public:
    int num;
    Int(int i) : num(i) {}
};

inline Int operator+(const Int &i1, const Int &i2) { return Int(i1.num + i2.num); }

int main(int argc, char const *argv[]) {
    // Calling an overloaded Operator Function Directly
    Int i = operator+(Int(22), Int(33));
    // Normal expression
    Int i2 = Int(7) + Int(8);
    std::cout << i.num << " " << i2.num << std::endl;
    
    // Overloaded versions of && or || operators do not preserve the evaluation order and
    // short-circuit evaluation properties of the built-in operators.
    int f = 3;
    int d = 32 || f++;
    std::cout << d << " " << f << std::endl;
    
    return 0;
}
