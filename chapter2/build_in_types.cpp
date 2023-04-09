#include <iostream>

/* 
 * Types are fundamental to any program:
 * They tell us what our data mean and What operations we can
 * perform on those data.
 */

int main(int argc, char const *argv[])
{
	std::cout << "The size of long double is: "	
			  << sizeof(long double) << " Bytes." << std::endl;

	std::cout << "The bool type: ture->" << true
			  << " and false->" << false << "." << std::endl;
        
	int i = -10;
	unsigned j = 2;
	unsigned char k = i;

	std::cout << "The type of signed -10 plus unsigned 2 is "
			  << i + j << "." << std::endl; 
	std::cout << "That is a unsigned!" << std::endl;

	std::cout << "The size of bool is " << sizeof(bool)
			  << " Bytes." << std::endl;

	/*
	 * If we assign an out-of-range value to an unsigned type, the
	 * result is the remainder of the value modulo the number of
	 * values the target type can hold(for 8-bits-integer, it's 256).
	 * 
	 * But if we assign an out-of-range value to a signed type, the
	 * result is undefined.
	 * 
	 * Advice: Avoid Undefined and Implementation-Defined Behavior.
	 */

	std::cout << "The value of unsigned k is " << (int)k << std::endl;

	bool m = 12;
	std::cout << "Assign a positive value to a bool type: " << m << std::endl;
	std::cout << "And the result of int type pluses bool type is " 
			  << m + i << std::endl;

	/*
	 * Rules of selecting types:
	 * 1. Use an unsigned type when you know that the values cannot be
	 *    negative.
	 * 2. Use int for integer arithmetic. short is usually too small
	 *    and, in pratice, long often has the same size as int. If your
	 *    data values are larger than the minimum guaranteed size of an
	 *    int (16 bits), the use long long.
	 * 3. Do not use plain char or bool in arithmetic expressions. If you
	 *    need a tiny integer, explicitly specify either signed char or
	 *    unsigned char.
	 * 4. Use double for floating-point computations; In fact, on some
	 *    machines, double-precision operations are faster than single. 
	 */
        
	return 0;
}