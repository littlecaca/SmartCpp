#include <iostream>

int main(int argc, char const *argv[])
{
	/*
	 * Undefined Operations about The Bitwise Operators
	 *
	 * If the operand is signed and its value is negative, then the way that
	 * the "sign bit" is handled in anumber of the bitwise operations is machine
	 * dependent. Moreover, doing a left shift that changes the value of the sign
	 * bit is undefined.
	 *
	 * So we strongly recommend using unsigned types with the bitwise oprators.
	 *
	 * The right-hand operand must not be negative and must be a value that is
	 * strictly less than the number of bits in the result. Otherwise, the operation
	 * is undefined.
	 *
	 * 
	 * Shift Operators Are Left Associative]
	 *
	 * An overloaded operator has the same precedence and associativity as the built-in
	 * version of that operator.
	 *
	 *
	 */			// the real memory space:
	unsigned n = 1;	// 0x01 0x00 0x00 0x00
	n <<= 8;	// 0x00 0x01 0x00 0x00
	n <<= 8;	// 0x00 0x00 0x01 0x00
				// low order

	// precedence: arithmetic > shift > relational > bitwise > logical
	if (n > 0 | 1 > 2)
		// relational operators has more precedence than bitwise operators
		std::cout << "true";
	else
		std::cout << "flase";

	std::cout << std::endl;
	// the char literals is signed
	std::cout << (~'q' << 6) << std::endl; 	// negative
	std::cout << (~1U) << std::endl;		// positive
	return 0;
}