#include <stdio.h>


int main(int argc, char const *argv[])
{
	/*
	 * The test aims to know the explict conversion in C.
	 */
	int i = 331, *pi = &i;
	double d = 21., *pd = &d;

	pi = (int *) pd;	// ok

	printf("%d\n", *pi);

	return 0;
}