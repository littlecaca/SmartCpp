/*
 * Name Lookup Happens at Compile Time
 *
 * 
 * 
 * Name Collisions and Inheritance
 * 
 * As usual, names definedn in an inner scope hide uses of that name
 * in the outer scope.
 * 
 * 
 * 
 * Using the Scope Operator to Use Hidden Members
 * 
 * struct Derived : Base {
 *      int get_base_mem() { return Base::mem; }
 * }
 * 
 * Best Pratices
 * Aside from overriding inerited virtual functions, a derived class usually
 * should not reuse names defined in its base class.
 * 
 * 
 * 
 * As Usual, Name Lookup Happens before Type Checking
 * 
 * 
 * 
 * Virtual Functions and Scope
 * 
 * 
 * 
 * Calling a Hidden Virtual Through the Base Class
 * 
 * 
 * 
 * Overriding Overloaded Functions
 * 
 * A derived class can override zero or more instances of the overloaded
 * functions it inherits. If a derived class wants to make all the overloaded
 * versions avaiable through its type, then it must override all of them or none
 * or them.
 * 
 * A using declaration for a base-class member function adds all the overloaded
 * instances of that function to the scope of the derived class.
 * 
 * The access to the overloaded versions that are not otherwise redefined by
 * the derived class will be the access in effect at the point of the using
 * declaration.
 * 
 */

class Base {
  public:
    int f() {};

};

class Derived : public Base {
    // int f() override {};
};