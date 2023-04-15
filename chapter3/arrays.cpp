#include <iostream>


/*
 * Arrays are a compound type.
 *
 * The dimension must be constexpr, and if dimension is greater than
 * the number of initializers, the initializers are used for the first
 * elements and any remaining elements are value initialized. Please pay
 * attention that the value initialization is different from the default
 * initialization.
 *
 *
 * No Copy or Assignment For Arrays.
 *
 *
 * When we use a variable to subscript an array, we normally should define
 * that variable to have type size_t, which in defined in the cstddef header
 * and is guaranteed to be large enough to hold the size of any object in memory.
 *
 *
 * Checking Subscript Values
 *
 * The most common source of security problems are buffer overflow bugs.
 * Such bugs occur when a program fails to check a subscript and mistakenly
 * uses memory outside the range of an array or similar data structure.
 */

int main(int argc, char const *argv[])
{
	// char a[6] = "Daniel";	// error: the compiler does not allow it
	// But this can be compiled in C. Oh, interesting!
	char a[7] = "Daniel";

	int b[7];
	// the sizeof operator retures the number of byte
	std::cout << "size:" << sizeof(b) << std::endl;

	std::cout << a[0] << std::endl;
	return 0;
}