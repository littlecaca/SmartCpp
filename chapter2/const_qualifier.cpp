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
	 *
	 */ 



	extern const int height;
	std::cout << "The height is " << height << std::endl;
	
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


	std::cout << s2 << std::endl;
	return 0;
}
