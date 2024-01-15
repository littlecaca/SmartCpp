#include <iostream>

/*
 * Type Aliases
 *
 * A type aliases is a name that is a synonym for another type.
 * The top-level consts are kept.
 * 
 *
 * The auto Type Specifier
 *
 * The auto tells the compiler to deduce the type from the initializer.
 * By implication, a variable that uses auto as its type specifier
 * must have an initializer.
 *
 *
 * Compound Types, const, and auto
 * 
 * The compiler adjusts the type to conform to normal initializer's
 * rules. Ordinarily, auto ignores top-level consts. But, please
 * pay attention, as usual, consts are not top-level when we bind 
 * a reference to an initializer.
 * 
 * 
 * The decltype Type specifier
 * 
 * decltype returns the type of its operand.
 * decltype(f()) sum = x;	// sum has whatever type f returns
 * Here, the compiler does not call f, but only uses the type
 * that such a call would return.
 * Generally speaking, decltype returns a reference type for
 * expressions that yield objects that can stand on the left-hand
 * side of the assignment. Pay attention please, just a variable
 * name don't belong to expressions that yield objects.
 *
 * When we apply decltype to a variable without any
 * parentheses, we get the type of that variable. And if we
 * wrap the variable's name in one or more sets of parentheses,
 * the compiler will evaluate the operand as an expression.
 *
 * There are two differences between the decltype specifier and
 * the auto specifier. The first one is they differs in dealing with
 * top-level consts. The second one is the decltype deduces out references
 * to expressions yielding objects that can stand on the left-hand
 * of assignments.
 */


int main(int argc, char const *argv[])
{
	// use a typedef to define a type alias
	typedef double wages;
	typedef const double * pwages;
	typedef const double * const cpwages;
	cpwages *cppw2 = nullptr;
	cpwages cpw1 = nullptr;

	// use an alias declaration to define a type alias
	using name = char *;

	// define mutiple variables which must have consistent type using auto
	auto num = 23.33 * 2, *p = &num;
	const int i = 2;
	// consts are not top-level when we bind a reference to an initializer
	auto &ref1 = i;	 	// ref1 is a const int & that is bound to num
	// auto &h = 42; 	// error: can't bind a plain reference to a literal
	const auto &h = 42;	// ok
	const auto &ref2 = i;
	auto pnum = &num;
	std::cout << *pnum << std::endl;
	std::cout << num << "\t" << *p << std::endl;
	std::cout << ref2 << std::endl;

	int j = 0, &r = j, *pj = &j;
	decltype(j) a;		// ok: a is an int
	decltype(r + 0) b;	// b is an nonreference int
	// decltype(*pj) c;	// error: c is an int &, must be initialized
	// decltype((j)) d; 	// error: d is an int &, must be initialized

    int nums[5];
    // We can use decltype to array to declare another array with the same size
    decltype(nums) nums2;
    std::cout << sizeof nums2 << std::endl;

	return 0;
}