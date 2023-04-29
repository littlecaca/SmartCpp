#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(int argc, char const *argv[])
{
	cout << "Input a set of integers:" << endl;
	int n;
	vector<int> nums;

	while (cin >> n)
		nums.push_back(n);

	decltype(nums.size()) i, j;
	
	for (i = 0; i < nums.size() - 2;
		i++)
		cout << nums[i] + nums[i + 1] << " ";

	cout << nums[i] + nums[i + 1] << endl;

	for (i = 0, j = nums.size() - 1;
		i < nums.size() - 1; i++, j--)
		cout << nums[i] + nums[j] << " ";
	cout << nums[i] + nums[j] << endl;


	return 0;
}