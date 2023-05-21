#include <stdio.h>

/*
 * Test whether the formal arguments of pointers to nonvoid type
 * in function can take void * arguments. 
 *
 * The result is that it's ok in C, but it's an error in C++.
 */

void test(char *a, char *b) {
	putchar(*a + *b);
}

int main(int argc, char const *argv[])
{
	char m = 'a', n = 2;
	double d = 21.;
	void *pm = &m, *pn = &n;
	test(pm, pn);
	double *pk = &d;
	pk = pm;	// it's ok in C
	return 0;
}