#include <string>
#include <iostream>
/**
 * Union
 *
 * A union is a special kind of class. A union may have multiple data members, but at
 * any point in time, only one of the members may have a value. When a value is
 * assigned to one member of the union, all other members become undefined. The
 * amount of storage allocated for a union is at least as much as is needed to contain
 * its largest data member. Like any class, a union defines a new type.
 *
 * Some, but not all, class features apply equally to unions. A union cannot have a
 * member that is a reference, but it can have members of most other types, including,
 * under the new standard, class types that have constructors or destructors. A union
 * can specify protection labels to make members public, private, or protected. By
 * default, like structs, members of a union are public.
 *
 * A union may define member functions, including constructors and destructors.
 * However, a union may not inherit from another class, nor may a union be used as
 * a base class. As a result, a union may not have virtual functions.
 *
 *
 * Defining a union
 *
 * We might have a process that handles different kinds of numeric or character data.
 *
 *
 * Using a union Type
 *
 * We can explicitly initialize a union in the same way that we can
 * explicitly initialize aggregate classes (§ 7.5.5, p. 298) by enclosing the initializer in a
 * pair of curly braces.
 *
 * If an initializer is present, it is used to initialize the first member.
 *
 *
 * Anonymous unions
 *
 * When we define an anonymous union the compiler
 * automatically creates an unnamed object of the newly defined union type.
 *
 * The members of an anonymous union are directly accessible in the scope where the
 * anonymous union is defined.
 *
 *
 * Note
 * An anonymous union cannot have private or protected members, nor
 * can an anonymous union define member functions.
 *
 *
 * unions with Members of Class Type
 *
 * unions with members that define their own constructors
 * and/or copy-control members are more complicated to use than unions that have
 * members of built-in type.
 *
 * When a union has members of built-in type, we can use ordinary assignment to
 * change the value that the union holds. Not so for unions that have members of
 * nontrivial class types. When we switch the union’s value to and from a member of
 * class type, we must construct or destroy that member, respectively: When we switch
 * the union to a member of class type, we must run a constructor for that member’s
 * type; when we switch from that member, we must run its destructor.
 *
 * When a union has members of built-in type, the compiler will synthesize the
 * memberwise versions of the default constructor or copy-control members. The same is
 * not true for unions that have members of a class type that defines its own default
 * constructor or one or more of the copy-control members. If a union member’s type
 * defines one of these members, the compiler synthesizes the corresponding member of
 * the union as deleted.
 *
 * The string class defines all five copy-control members and the
 * default constructor. If a union contains a string and does not define its own
 * default constructor or one of the copy-control members, then the compiler will
 * synthesize that missing member as deleted. If a class has a union member that has
 * a deleted copy-control member, then that corresponding copy-control operation(s) of
 * the class itself will be deleted as well.
 *
 *
 * Using a Class to Manage union Members
 *
 * Because of the complexities involved in constructing and destroying members of class
 * type, unions with class-type members ordinarily are embedded inside another class.
 * That way the class can manage the state transitions to and from the member of class
 * type.
 *
 * To keep track of what type of value the union holds, we usually define a separate
 * object known as a discriminant.
 *
 * Unlike ordinary members of a class type, class members that are part of a union
 * are not automatically destroyed. The destructor has no way to know which type
 * the union holds, so it cannot know which member to destroy.
 *
 *
 * Managing the Discriminant and Destroying the string
 *
 *
 *
 * Managing Union Members That Require Copy Control
 *
 *
 */

union Token
{
    /* data */
    char cval;
    int ival;
    double dval;
};

static union
{
    char cval;
    int ival;
    double dval;
};

// static union
// {
//     int rr;
//     std::string name;
// };

class Token2
{
public:
    Token2() : tok(INT), ival(0) {}
    Token2(const Token2 &t) : tok(t.tok) { copyUnion(t); }
    Token2(Token2 &&t) : tok(t.tok) { moveUnion(std::move(t)); }
    Token2 &operator=(Token2 &&);
    Token2 &operator=(const Token2 &);
    ~Token2()
    {
        if (tok == STR)
            sval.~basic_string();
    }
    Token2 &operator=(const std::string &);
    Token2 &operator=(char);
    Token2 &operator=(int);
    Token2 &operator=(double);

private:
    // unscoped enumeration
    // Used as the discriminant
    enum
    {
        INT,
        CHAR,
        DBL,
        STR
    } tok;
    union
    {
        char cval;
        int ival;
        double dval;
        std::string sval;
    };

    void copyUnion(const Token2 &);
    void moveUnion(Token2 &&);
};

void Token2::copyUnion(const Token2 &t)
{
    switch (t.tok)
    {
    case INT:
        ival = t.ival;
        break;
    case CHAR:
        cval = t.cval;
        break;
    case DBL:
        dval = t.dval;
        break;
    case STR:
        new (&sval) std::string(t.sval);
        break;
    }
}

void Token2::moveUnion(Token2 &&t)
{
    switch (t.tok)
    {
    case INT:
        ival = t.ival;
        break;
    case CHAR:
        cval = t.cval;
        break;
    case DBL:
        dval = t.dval;
        break;
    case STR:
        new (&sval) std::string(std::move(t.sval));
        break;
    }
}

Token2 &Token2::operator=(Token2 &&t)
{
    if (tok == STR && t.tok != STR)
        sval.~basic_string();
    if (tok == STR && t.tok == STR)
        sval = std::move(t.sval);
    else
        moveUnion(std::move(t));
    tok = t.tok;

    return *this;
}

Token2 &Token2::operator=(const Token2 &t)
{
    if (tok == STR && t.tok != STR)
        sval.~basic_string();
    if (tok == STR && t.tok == STR)
        sval = t.sval;
    else
        copyUnion(t);
    tok = t.tok;

    return *this;
}

Token2 &Token2::operator=(const std::string &rhs)
{
    if (tok == STR)
        sval = rhs;
    else new (&sval) std::string(rhs);
    return *this;
}

Token2 &Token2::operator=(char rhs)
{
    if (tok == STR)
        sval.~basic_string();
    cval = rhs;
    return *this;
}

Token2 &Token2::operator=(int rhs)
{
    if (tok == STR)
        sval.~basic_string();
    ival = rhs;
    return *this;
}

Token2 &Token2::operator=(double rhs)
{
    if (tok == STR)
        sval.~basic_string();
    dval = rhs;
    return *this;
}

int main(int argc, char const *argv[])
{
    Token t1 = {'1'};
    std::cout << t1.ival << std::endl;

    cval = '1';
    std::cout << ival << std::endl;
    ival = 65;
    std::cout << cval << std::endl;

    Token2 t2, t3, t4;

    t2 = "you";
    t3 = 3.4;
    t4 = 1;
    t2 = t3;
    
    return 0;
}
