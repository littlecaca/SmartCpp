#include <iostream>

int main(int argc, char const *argv[])
{
	/*
	 * Braced lists of initializers can now be used whenever
	 * we initialize an object and in some cases when we assign
	 * a new value to an object.
	 * 
	 * Attention:
	 * The compiler will not let us list initialize variables of 
	 * built-in type if the initializer might lead to loss of
	 * information.
	 *
	 * About Initialization:
	 * We recommend initializing every object of built-in type.
	 * It is not always necessary, but it is easier and safer to 
	 * provide an initializer until you can be certain it is safe
	 * to omit the initializer.
	 */

	long double ld = 3.1415926;
	int a{ld}, b = {ld};	// error: narrowing conversion required
	int c(ld), d = ld;		// ok: but value will be truncated


	return 0;
}