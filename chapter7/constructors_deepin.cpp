#include "access_specifiers.h"
#include <iostream>

using std::string;

/*
 * If we do not explicitly initialize a member in the constructor initializer list,
 * that member is default initialized before the constructor body starts executing.
 * 
 * We can often, but not always, ignore the distinction between whethera member is initialized
 * or assigned. Members that are const or references must be initailized. Similarly, members
 * that are of a class type that does not define a default constructor also must be initialized.
 * 
 * We must use the constructor initializer list to provide values for members that are const,
 * reference, or of a class type that does not have a defalut constructor.
 * 
 * 
 * In many classes, the distinction between initialization and assignment is strictly a matter of
 * low-level efficiency.
 */

// another version: no constructor initializers
Sales_data::Sales_data(const string &s, unsigned cnt) {
    bookNo = s;
    units_sold = cnt;
    revenue = 0;
}

// const or references must be initailized
// by the time the body of the constructor begins executing, initialization
// is complete.
class ConstRef {
  public:
    // ConstRef(int i); error: ci and ri must be initialized
    ConstRef(int ii) : ci(ii), i(ii), ri(i) {}
  private:
    const int ci;
    int i;
    int &ri;
};


int main(int argc, char const *argv[])
{
    /* code */
    ConstRef cr(7);
    return 0;
}
