#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	std::vector<int> intvec{1, 2, 3, 4};
	int int_arr[4];
	int *p = int_arr;
	for (int n : intvec)
		*p++ = n;

	for (p = int_arr; p != int_arr + 4; p++)
		std::cout << *p;

	std::cout << std::endl;

	return 0;
}