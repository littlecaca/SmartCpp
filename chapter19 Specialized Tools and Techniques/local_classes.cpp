#include <string>
#include <iostream>

/**
 * Local Classes
 * 
 * A class can be defined inside a function body. Such a class is called a local class. 
 * A local class defines a type that is visible only in the scope in which it is defined. Unlike
 * nested classes, the members of a local class are severely restricted.
 * 
 * Note
 * All members, including functions, of a local class must be completely defined
 * inside the class body. As a result, local classes are much less useful than
 * nested classes.
 * 
 * Similarly, a local class is not permitted to declare static data members, there
 * being no way to define them.
 * 
 * 
 * Local Classes May Not Use Variables from the Function’s Scope
 * 
 * The names from the enclosing scope that a local class can access are limited. A local
 * class can access only type names, static variables (§ 6.1.1, p. 205), and
 * enumerators defined within the enclosing local scopes. A local class may not use the
 * ordinary local variables of the function in which the class is defined.
 * 
 * 
 * Normal Protection Rules Apply to Local Classes
 * 
 * The enclosing function has no special access privileges to the private members of
 * the local class. Of course, the local class could make the enclosing function a friend.
 * 
 * 
 * Name Lookup within a Local Class
 * 
 * Name lookup within the body of a local class happens in the same manner as for
 * other classes. Names used in the declarations of the members of the class must be in
 * scope before the use of the name. Names used in the definition of a member can
 * appear anywhere in the class.
 * 
 * 
 * Nested Local Classes
 * 
 * It is possible to nest a class inside a local class. In this case, the nested class
 * definition can appear outside the local-class body. 
 * 
 * A class nested in a local class is itself a local class, with all the attendant
 * restrictions. All members of the nested class must be defined inside the body of the
 * nested class itself.
 */

int main(int argc, char const *argv[])
{
    return 0;
}


template <typename T, size_t SIZE>
void print(T array[SIZE])
{

}