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


	for(auto it1 = nums.cbegin(), it2 = nums.cend();
		it1 != it2 - 1; it1++)
		cout << *it1 + *(it1 + 1) << " ";
	cout << endl;

	for (auto it1 = nums.cbegin(), it2 = nums.cend() - 1, end = nums.cend();
		it1 != end; it1++, it2--)
		cout << *it1 + *it2 << " ";
	cout << endl;


	return 0;
}