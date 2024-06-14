#include <iostream>
#include <vector>

/**
 * Nested Classes
 * 
 * A class can be defined within another class. Such a class is a nested class, also
 * referred to as a nested type. Nested classes are most often used to define
 * implementation classes, such as the QueryResult class we used in our text query
 * example (§ 12.3, p. 484).
 * 
 * Nested classes are independent classes and are largely unrelated to their enclosing
 * class. An object of the nested type does not have members defined by the
 * enclosing class. Similarly, an object of the enclosing class does not have members
 * defined by the nested class.
 * 
 * The name of a nested class is visible within its enclosing class scope but not outside
 * the class. Like any other nested name, the name of a nested class will not collide with
 * the use of that name in another scope.
 * 
 * A nested class defines a type member in its enclosing class. As with any other
 * member, the enclosing class determines access to this type. A nested class defined in
 * the public part of the enclosing class defines a type that may be used anywhere. A
 * nested class defined in the protected section defines a type that is accessible only
 * by the enclosing class, its friends, and its derived classes. A private nested class
 * defines a type that is accessible only to the members and friends of the enclosing
 * class.
 * 
 * 
 * Declaring a Nested Class
 * 
 * 
 * 
 * Defining a Nested Class outside of the Enclosing Class
 * 
 * Inside TextQuery we declared QueryResult but did not define it. As with member
 * functions, nested classes must be declared inside the class but can be defined either
 * inside or outside the class.
 * 
 * 
 * Warning
 * Until the actual definition of a nested class that is defined outside the class
 * body is seen, that class is an incomplete type (§ 7.3.3, p. 278).
 * 
 * 
 * Defining the Members of a Nested Class
 * 
 * 
 * 
 * Nested-Class static Member Definitions
 * 
 * 
 * Name Lookup in Nested Class Scope
 * 
 * Normal rules apply for name lookup (§ 7.4.1, p. 283) inside a nested class. Of course,
 * because a nested class is a nested scope, the nested class has additional enclosing
 * class scopes to search.
 * 
 * 
 * The Nested and Enclosing Classes Are Independent
 * 
 * Although a nested class is defined in the scope of its enclosing class, it is important to
 * understand that there is no connection between the objects of an enclosing class and
 * objects of its nested classe(s). A nested-type object contains only the members
 * defined inside the nested type. Similarly, an object of the enclosing class has only
 * those members that are defined by the enclosing class. It does not contain the data
 * members of any nested classes.
 */


class TextQuery
{
public:
    using line_no = size_t;
    static void print() {}
    /**
     * nested classes must be declared inside the class but can be defined either
     * inside or outside the class.
    */

    class QueryResult;
};

class TextQuery::QueryResult
{
public:
    QueryResult();
    void f(line_no)
    {
        print();
    }
    static int id;
};


TextQuery::QueryResult::QueryResult() {}

int TextQuery::QueryResult::id = 12;

class Derived : public TextQuery
{
public:
    void f(line_no)
    {
        print();
    }
};


int main(int argc, char const *argv[])
{

    return 0;
}
