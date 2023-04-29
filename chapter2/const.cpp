#include <iostream>

int main(int argc, char const *argv[])
{
	// A const type can use most but not all of the 
	// same operations as its nonconst version
	// Only the operations changing the value of const variables
	// are illegal

	/*
	 * By Default, const Objects Are Local to a File
	 *
	 * When a const object is initialized from a compile-time
	 * constant, the compiler will usually replace uses of the
	 * variable with its corresponding value during compilation
	 * 
	 * Thereby that also leads to a problem. If the const object is
	 * defined in another file, the compiler don't know the const's
	 * initializer, so it can't replace the uses of the const object.
	 * 
	 * In order to see the initializer, the variable must be defined
	 * in every file that wants to use the variable's value.
	 *
	 * Luckily, the const objects are defined as local to file by default.
	 *
	 * To define a single instance of a const variable among multiple
	 * files, we use the keyword extern on both its definition and
	 * declaration(s);
	 *
	 * Terminology: const Reference Is A Reference to const
	 *
	 * As we have learned, there are two exceptions to the rule that
	 * the type of a reference must match the type of the object to
	 * which it refers.
	 * One of them is we can initialze a reference to const from any
	 * expression that can be converted to the type of the reference.
	 *
	 * Top Level const and Low Level const
	 *
	 * The top-level const indicates that the pointer itself is a const.
	 * When a pointer can point to a const object, we refer to that
	 * const as a low-level const. 
	 * 
	 * When we copy an object, top level consts are ignored. But please
	 * pay attention, consts are not top-level when we bind a reference
	 * to an initializer.
	 *
	 * constexpr and Constant Expressions
	 * 
	 * A constant expression is an expression whose value cannot change
	 * and that can be evaluated at compile time.
	 * Whether a given object (or expression) is a constant expression
	 * depends on the types and the initializers.
	 *
	 * We can ask the compiler to verify that a variable is a constant
	 * expression by declaring the variable in a constexpr declaration.
	 * 
	 * Literal Types
	 * The types we can use in a constexpr are known as "literal types"
	 * because they are simple enough to have literal values.
	 * Of the types we have used so far, the arithmetic, reference, and
	 * pointer types are literal types.
	 */ 



	// extern const int height;
	// std::cout << "The height is " << height << std::endl;
	
	const int num = 100;
	const int &refNum = num;	// ok
	// int &ref2 = num; 			// error: nonconst reference to a const object

	double s = 3.33;
	const int &age = 21;		// ok
	const int &speed = s;		// ok
	// the compiler transforms the aboce code into someting like this:
	// const int temp = speed;
	// const int &speed = temp;
	// in this case, speed is bound to a temporary object. A temporary object
	// is an unnamed object created by the compiler when it needs a place to
	// store a result from evaluating an expression.
	// If the speed is not const, we may want to change speed to change s,
	// but actually we can only change temp, and that almost surely not what
	// we want, so the language makes it illegal 

	// it is ok because the reference to const can refer to nonconst object
	const int &refS = s;	// ok, and then either the refS or the reference 
							// to the refS(the object it points to) can't be changed directly.
	s += 1;					// ok, because s is not const
	int s2 = refS;			// ok
	// refS++;				// error: the refS is realy-only
	// int &ref3 = refS;	// error: bindind reference to nonconst 
							// to object that is refered by reference
							// to const
	/*
	 * Rule: can't assign more loose qualifier than the variable of
	 * initializer to the compound type.
	 */

	const int t1 = 30;
	// int *pt1 = &t1;		// error: invalid conversion
	// int &reft1 = t1;		// error

	const int *pt2;			
	pt2 = &t1;				
	// int * const pt3;		// error: must be initialized

	const int *pt4 = &s2;
	s2 += 1;				// ok
	// *pt4 += 1;			// error

	/*
	 * It may be helpful to think of pointers and references
	 * to const as pointers or references "that think they point
	 * or refer to const".
	 */

	int * const pt5 = &s2;

	std::cout << *pt2 << std::endl;
	std::cout << s2 << std::endl;
	

	// constexpr and Constant Expressions
	const int max_files = 20;			// is a constant expression
	const int limit = max_files + 1;	// is a constant expression
	int staff_size = 27;				// not a constant expression
	// const int sz = get_size(); 		// not a constant expression

	constexpr int mf = 20;				// is a constant expression
	constexpr int limit_mf = mf + 1;	// is a constant expression
	// constexpr int sz_mf = size();	// ok only if the size() is a
										// constexpr function

	/*
	 * Pointers and constexpr
	 * It is important to understand that when we define a pointer in
	 * a constexpr declaration, the constexpr specifier applies to
	 * the pointer, not the type to which the pointer points.
	 *
	 */
	// constexpr const int *pmf = &mf;	// error: &mf is not a constant expression
	// the constexpr imposes a top-level const on the objects it defines
	constexpr int *pmf = nullptr;
	// std::cout << *pmf << std::endl;

	return 0;
}
