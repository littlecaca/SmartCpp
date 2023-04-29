#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(int argc, char const *argv[])
{
	cout << "Input a set of integers: " << endl;
	vector<int> nums(11, 0);
	int n;
	auto it = nums.begin();

	while (cin >> n)
		(*(it + (n / 10)))++;

	for (auto end = nums.end(); it != end; it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}