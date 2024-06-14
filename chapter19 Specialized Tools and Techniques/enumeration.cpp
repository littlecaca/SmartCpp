/**
 * Enumerations
 *
 * Enumerations let us group together sets of integral constants.
 * Like classes, each enumeration defines a new type. Enumerations
 * are literal types (§ 7.5.6, p. 299).
 *
 * C++ has two kinds of enumerations: scoped and unscoped. The new standard
 * introduced scoped enumerations. We define a scoped enumeration using the
 * keywords enum class (or, equivalently, enum struct), followed by the
 * enumeration name and a comma-separated list of enumerators enclosed in curly
 * braces.
 *
 * We define an unscoped enumeration by omitting the class (or struct)
 * keyword. The enumeration name is optional in an unscoped enum.
 *
 *
 * Enumerators
 *
 * Enumerators are const and, if initialized, their initializers must be constant
 * expressions.
 * 
 * 
 * Like Classes, Enumerations Define New Types
 * 
 * An enum object may be initialized or assigned only by one of its enumerators or by
 * another object of the same enum type.
 * 
 * Objects or enumerators of an unscoped enumeration type are automatically
 * converted to an integral type. As a result, they can be used where an integral value is
 * required. But scoped enumerations are not implicitly converted.
 * 
 * 
 * Specifying the Size of an enum
 * 
 * Although each enum defines a unique type, it is represented by one of the built-in
 * integral types. Under the new standard, we may specify that type by following the
 * enum name with a colon and the name of the type we want to use.
 * 
 * If we do not specify the underlying type, then by default scoped enums have int as
 * the underlying type. There is no default for unscoped enums. When the underlying
 * type is specified (including implicitly specified for a scoped enum), it is an error for an
 * enumerator to have a value that is too large to fit in that type.
 * 
 * 
 * Forward Declarations for Enumerations
 * 
 * Under the new standard, we can forward declare an enum. An enum forward
 * declaration must specify (implicitly or explicitly) the underlying size of the enum.
 * 
 * Because there is no default size for an unscoped enum, every declaration must include
 * the size of that enum.
 * 
 * As with any declaration, all the declarations and the definition of a given enum must
 * match one another. In the case of enums, this requirement means that the size of the
 * enum must be the same across all declarations and the enum definition. Moreover, we
 * cannot declare a name as an unscoped enum in one context and redeclare it as a
 * scoped enum later.
 * 
 * 
 * Parameter Matching and Enumerations
 * 
 * Because an object of enum type may be initialized only by another object of that
 * enum type or by one of its enumerators (§ 19.3, p. 833), an integral value that
 * happens to have the same value as an enumerator cannot be used to call a function
 * expecting an enum argument.
 * 
 * Although we cannot pass an integral value to an enum parameter, we can pass an
 * object or enumerator of an unscoped enumeration to a parameter of integral type.
 * 
 * Regardless of its underlying
 * type, objects and the enumerators of Tokens are promoted to int. Enumerators and
 * values of an enum type are not promoted to unsigned char, even if the values of
 * the enumerators would fit.
 */

// unscoped enumeration
enum
{
    Yellow,
    Red
};
enum Animal
{
    rabbit,
    rat
};

// scoped enumeration
enum class Color
{
    Black = 1,
    Yellow
};

// an enumerator value need not be unique
enum class intTypes
{
    charTyp = 8,
    shortTyp = 16,
    intTyp = 16,
    longTyp = 32,
    long_longTyp = 64
};

enum Length : unsigned long long 
{

};

// forward declaration
// forward declaration of unscoped enum named intValues
enum intValues : unsigned long long;    // unscoped, must specify a type
enum class open_modes;                  // scoped enums can use int by default

// // error: declarations and definition must agree whether the enum is scoped or unscoped
// enum class intValues;
// enum intValues; // error: intValues previously declared as scoped enum
// enum intValues : long; // error: intValues previously declared as int


// enum class cloud;
// enum class cloud : long;

int main(int argc, char const *argv[])
{
    Color c1 = Color::Black;

    // int i1 = Color::Black;
    int i2 = Animal::rabbit;
    return 0;
}
