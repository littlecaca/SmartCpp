#include <iostream>

int main(int argc, char const *argv[])
{
	int m = 1, n = 2, k = 3, j = 4;

	m += n;
	k = k + j;

	std::cout << m << k << std::endl;
	return 0;
}