#include <stdio.h>

int main(int argc, char const *argv[])
{
	struct item
	{
		int count;
		long long id;
		const char *name;
		double price;
	};

	typedef struct item it;

	it i1 = {12, 213, "siso", 32.99};
	// i1 = {13};	// This is wrong, because this only is permitted in initialization.

	i1.count = 3;
	i1.name = "kaffer";

	int array[][3] = {
		{1, 2, 3}, 
		{4, 5, 6}
	};
	int (*ap)[3] = array;
	int **pointer = array;	// error: the pointer is actually the &array[0][0] here
	printf("pointer[0]: %d\n", pointer[0]);
	printf("%d\n", ap[0][1]);

	printf("%d\t%lld\t%s\t%f\n", i1.count, i1.id, i1.name, i1.price);


	return 0;
}