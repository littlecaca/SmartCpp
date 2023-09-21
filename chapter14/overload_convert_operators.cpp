#include <iostream>
#include <stdexcept>

/*
 * Conversion Operators
 *
 * A converison operator is a special kind of member function that
 * converts a value of a class type to a value of some other type.
 *
 * Conversion operators can be defined for any type (other than void) that
 * can be a function return type.
 *
 * Note
 * A conversion must be a member function, may not specify a return type,
 * and must have an empty parameter list. The function usually should be const.
 *
 * 
 * 
 * Caution: Avoid Overuse of Conversion Functions
 * 
 * Some conversions can be misleading.
 * 
 * 
 * 
 * Conversion Operators Can Yield Supring Results
 * 
 * In pratice, classes rarely provide conversion operations.
 * It is not uncommon for classes to define conversions to bool.
 * 
 * 
 * explicit Conversion Operators
 * 
 * As with explicit constructor, the compiler won't (generally) use
 * an explicit conversion operator for implicit conversions.
 * 
 * If the conversion operator is explicit, with one exception,
 * we must do so explicitly through a cast.
 * 
 * The exception is that the compiler will apply an explicit conversion
 * to an expression used as a condition.
 * 
 * 
 * Conversion to bool
 * 
 * Best Practices
 * Conversion to bool is usually intended for use in conditions.
 * As a result, operator bool ordinarily should be defined as explicit.
 * 
 * 
 * 
 * ===========================================
 *       Avoiding Ambiguous Conversions
 * ===========================================
 * 
 * 
 * If a class has one or more conversions, it is important to ensure
 * that there is only one way to convert from the class type to the 
 * target type.
 * 
 * There are two ways that multiple conversion paths can occur.
 * The first happens when two classes provide mutual conversions.
 * 
 * The second way to generate multiple conversion paths is to define
 * multiple conversions from or to types that are themselves related
 * by conversions. A given class ordinarily ought to define at most
 * one conversion to or from an arithmetic type.
 * 
 * Warning
 * Ordinarily, it is a bad idea to define classes with mutual conversions
 * or to define conversions to or from two arithmetic types.
 * 
 * 
 * 
 * Argument Matching and Mutual Conversions
 * 
 * 
 * Ambiguities and Multiple Conversions to Built-in Types
 * 
 * 
 * When a user-defined conversion is used, the rank of the standard conversion,
 * if any, is used to select the best match.
 * 
 * 
 * 
 * Overloaded Functions and Converting Construtors
 * 
 * Choosing among multiple conversions is further complicated when we
 * call an overloaded function.
 * 
 * Warning
 * Needing to use a constructor or a cast to convert an argument in a call
 * to an overloaded function is a sign of bad design.
 * 
 * 
 * 
 * Caution: Conversions and Operators
 * 
 * The easiest rule of all: With the exception of an explicit conversion
 * to bool, avoid defining conversion functions and limit nonexplicit
 * constructors to those that are "obviously right".
 * 
 * Avioid conversions to the built-in arthmetic types. 
 * If you do define a conversion to an arithmetic type, then:
 * 
 * Do not define overloaded versions of the operators that take
 * arithmetic types. If users need to use these operators, the conversion
 * operation will convert objects of your type, and then the built-in
 * operators can be used.
 * 
 * Do not define a conversion to more than one arithmetic type. Let the 
 * standard conversions provide conversions to the other arithmetic types.
 * 
 * 
 * 
 * Overloaded Functions and User-Defined Conversion
 * 
 * In a call to an overloaded function, if two (or more) user-defined
 * conversions provide a viable match, the conversions are considered
 * equally good. The rank of any standard conversions that might
 * or might not be required is not considered. Whether a built-in conversion
 * is also considered only if the overloaded set can be matched using 
 * the same conversion function.
 * 
 * 
 * 
 * Function Matching and Overloaded Operators
 * 
 * Overloaded operators are overloaded functions. Normal function matching
 * is used to determine which operator--built-in or overloaded--to apply
 * to a given expression.
 * 
 * When we use an overloaded operator in an expression, there is nothing
 * to indicate whether we're using a member or nonmember function. Therefore,
 * both member and nonmember versions must be considered.
 * 
 * For example:
 * 		SmallInt s1, s2;
 * 		SmallInt s3 = s1 + s2;
 * 		int i = s3 + 0;		// error: ambiguous
 * 
 * Warning
 * Providing both conversion functions to an arithmetic type and overloaded
 * operators for the same class type may lead to ambiguities between the
 * overloaded operators and the built-in operators.
 * 		
 */

class SmallInt {
	size_t val;

  public:
	// This is a convertible and default constructor
	SmallInt(int i = 0) : val(i) {
		std::cout << "convert or default construction" << std::endl;
		if (i < 0 || i > 255)
			throw std::out_of_range("Bad SmallInt value");
	}
	// A conversion function does not specify a return type
	// But each conversion function must return a value of its
	// corresponding type.
	operator int() const { return val; }
	SmallInt(const SmallInt &) = delete;
	SmallInt &operator=(const SmallInt &) = delete;
};

int main(int argc, char const *argv[])
{
    SmallInt si{};
	// SmallInt si2 = si;
	SmallInt si3 = 4;	// copy elision
	int i = si3 + 5;
	double d = si3 + 3.14;
	std::cout << i << std::endl;
	std::cout << d << std::endl;

    return 0;
}
