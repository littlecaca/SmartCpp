#include <stdio.h>

int main(int argc, char const *argv[])
{
	int m = 1, n = 2, k = 3, j = 4;
	register int x = 5, y = 6;

	m += n;
	k = k + j;
	x += y;
	printf("%d, %d, %d\n", m, k, x);

	return 0;
}