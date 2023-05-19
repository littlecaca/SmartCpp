#include <iostream>

int main(int argc, char const *argv[])
{
	/*
	 * The result of a comma expression is the value of its right-hand expression.
	 * The result is an lvalue if the right-hand expression is an lvalue.
	 */
	
	int m, n;
	m = 1, n = 2;

	std::cout << m << " " << n << std::endl;
	return 0;
}