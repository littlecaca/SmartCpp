#include <iostream>
#include <vector>
#include <cctype>
#include <string>


using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
	cout << "Input ints seperated by space:" << endl;

	vector<string> nums;
	string n;
	
	while (cin >> n)
		nums.push_back(n);
	
	if (nums.size() == 0) {
		cout << "There is no string!" << endl;
		return -1;
	}

	cout << "{";
	for (auto i : nums)
		cout << i << ", ";
	cout << "}" << endl;

	return 0;
}