#include <iostream>

int main(int argc, char const *argv[])
{
	/*
	 * cast-name<type> (expression)
	 *
	 * The cast-name may be one of static_cast, dynamic_cast, const_cast, and reinterpret_cast,
	 * which determines what kind of conversion is performed.
	 *
	 *
	 * Advice: Aovid Casts
	 *
	 * This advice is particularly applicable to reinterpret_casts. Such casts are always hazardous.
	 * A const_cast can be useful in the context of overloaded functions, and other uses of const_cast
	 * often indicate a design flaw. The other casts, static_cast and dynamic_cast, should be needed
	 * infrequently. Every time you write a cast, you should think hard about whether you can achieve
	 * the same result in a different way. If the cast is unavoidable, errors can be mitigated by 
	 * limiting the scope in which the casr value is used and by documenting all assumptions about
	 * the types involved.
	 */

	/*
	 *	static_cast
	 */

	// Other than those involving low-level const, any well-defined type conversion 
	// can be requested using a static_cast

	int i = 97, j = 21;
	double d = 22.;
	double *pd = &d;
	double *pd2 = &d;
	void *pi = &i;
	double slope = static_cast<double>(j) / i;
	pd = static_cast<double *>(pi);
	char c2 = static_cast<char>(i);

	std::cout << c2 << std::endl;
	std::cout << *pd << std::endl;
	// pd = pi;	// error: invalid conversion from ‘void*’ to ‘double*’
	// char *pc2 = static_cast<char *>(pd);	// error: invalid ‘static_cast’ from type ‘double*’ to type ‘char*’


	/*
	 * const_cast
	 */

	// const_cast only changes constness
	// error: invalid use of ‘const_cast’ with type ‘double’, which is not a pointer, reference, nor a pointer-to-data-member type
	// double slope2 = const_cast<double>(j) / i;	


	// a const_cast changes only a low-level const in its operand
	// a cast that converts a const object to a nonconst type is called "casts away the const"
	// however, using a const_cast in order to write to a const object is undefined

	// here, if c is const, then *p = 'b' will have no effect
	char c = 'a';
	const char* pc = &c;
	char *p = const_cast<char*>(pc);
	*p = 'b';
	std::cout << c << std::endl;

	/*
	 * reinterpret_cast
	 */

	// a reinterpret_cast generally performs a low-level reinterpretation of the bit pattern of its
	// operands. 
	int *pi2 = reinterpret_cast<int *>(pd);	
	char *pc3 = reinterpret_cast<char *>(pd2);
	std::cout << *pi2 << std::endl;
	std::cout << (short)*pc3 << std::endl;

	/*
	 * Old-Style Casts
	 * 
	 * type (expr);
	 * (type) expr;
	 *
	 * An old-style cast has the same behavior as a const_cast, a static_cast, or a reinterpret_cast.
	 * But the old-style casts are less visible than named casts.
	 */



	return 0;
}