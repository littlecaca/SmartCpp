#include <iostream>
#include <string>

/*
 * Tip
 * Classes that define both an arithmetic operator and the related compound
 * assignment ordinarily ought to implement the arithmetic operator by using
 * the compound assignment.
 * 
 * 
 * 
 * Equality Operators
 * 
 * Best Pratices
 * Classes for which there is a logical meaning for equality normally should 
 * define operator==. Classes that define == make it easier for users to use
 * the class with the library algorithms.
 * 
 * 
 * 
 * Relational Operators
 * 
 * Ordinarily the relational operators should:
 * 1.Define an ordering relation that is consistent with the requirements for use
 * as a key to an associative container; and
 * 2.Define a relation that is consistent with == if the class has both operators.
 * In particular, if two objects are !=, then one obejct should be < the other.
 * 
 * 
 * 
 * Best Practices
 * If a single logical definition for < exists, classes usually should define
 * the < operator. However, if the class also has ==, define < only if the
 * definitions of < and == yield consitent results.
 */

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
