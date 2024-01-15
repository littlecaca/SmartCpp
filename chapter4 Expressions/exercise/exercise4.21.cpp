#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (auto it = nums.begin(), last = nums.end(); it != last; ++it)
		*it = *it % 2 == 0 ? *it : *it * 2;

	for (const int &item : nums)
		std::cout << item << " ";
	std::cout << std::endl;
	return 0;
}