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

	printf("%d\t%lld\t%s\t%f\n", i1.count, i1.id, i1.name, i1.price);


	return 0;
}