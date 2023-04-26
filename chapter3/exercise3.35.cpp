#include <iostream>
#include <iterator>

int main(int argc, char const *argv[])
{
	int nums[100] = {1, 2, 3, 4, 5, 6, 7, 8};

	for (int *i = nums, *last = std::end(nums); i < last; i++)
		*i = 0;

	for (int *i = nums, *last = std::end(nums); i < last; i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	return 0;
}