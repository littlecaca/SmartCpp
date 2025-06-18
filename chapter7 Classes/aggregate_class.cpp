#include <iostream>
#include <string>

using std::string;

/*
 * An aggregate class give users direct access to its members and has special
 * initialization syntax. A class is an aggregate if:
 *      1. All of its members are public
 *      2. It does not define any constructors
 *      3. It has no in-class initializers
 *      4. It has no base classes or virtual functions, which are class-related features.
 * Just like original C style struct but it can contain member function.
 * The most important feature of the aggregate class is that it can be initialized by a initializer list
 * with members having different types.
 */


// an example of aggregate class
struct Data {
    int ival;
    string s;
};

int main(int argc, char const *argv[])
{
    // we can initialize the data members of an aggregate class by providing a braced list of member initializers
    // the initializers must appear in declaration order of the data members
    // if the initializers are less than the members it contains, the trailing members are value initialized
    // the list of initializers must not contain more elements than the class has members
    Data val1 = {0, "Anna"};
    Data val2 {1, "jlk"};
    return 0;
}
