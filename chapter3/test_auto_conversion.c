#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i = -12;
	unsigned j = 2;

	if (j < i)
		// C/C++
		printf("j < i\n");
	else
		printf("j >= i\n");
	return 0;
}