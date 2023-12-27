#include <iostream>
#include <string>

/*
 * Pure Virtual Functions
 * 
 * Unlike ordinary virtuals, a pure virtual function does not have to be
 * defined. We specify that a virtual function is a pure vittual by writing
 * = 0 in place of a function body. The = 0 may appear only on the
 * declaration of a virtual function in the class body.
 * 
 * It is worth noting that we can provide a definnition for a pure virtual.
 * However, the function body must be defined outside the class. 
 * 
 * 
 * 
 * Class with Pure Virtuals Are Abstract Base Classes
 * 
 * An abstract base class defines an interface for subsequent classes
 * to override. We cannot (directly) create objects of a type that is an abstract
 * base class. 
 * 
 * A Derived Class Constructor Initializes Its Direct Base Class Only
 * 
 * Key Concept: Refactoring
 * 
 * Refactoring involves redesigning a class hierarchy to move operations and/or
 * data from one class to another.
 */

int main(int argc, char const *argv[])
{
    
    /* code */
    return 0;
}
