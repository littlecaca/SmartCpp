#include <stdlib.h>
#include <stdio.h>

/*
 * Test the action of the % operator.
 *
 * The result is that C++ and C have the same feature about % operator.
 */

int main(int argc, char const *argv[])
{
	printf("div(-2, 3) = %d\n", div(-2, 3).rem);
	unsigned i = -2;
	printf("(unsigned)-2 = %u\n", i);
	printf("-2 % 3 = %d\n", -2 % 3);	// possible result: 0...-2(C/C++, js, java), -1...1(python)

	if (div(3, -2).quot == 3 / -2)
		printf("yes\n");
	if (div(-2, 9).quot == -2 / 9)
		printf("yes\n");
	if (div(9, -2).quot == 9 / -2)
		printf("yes\n");


	return 0;
}