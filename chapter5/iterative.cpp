#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
	/*
	 * while loop
	 */

	vector<int> v;
	int i;
	// a `while` loop is generally used when we want to iterate indefinitely
	while (cin >> i)
		v.push_back(i);

	// a `while` loop is also useful when we want access to the value of the loop control variable
	// after the loop finishes
	auto beg = v.begin();
	while (beg != v.end() && *beg > 0)
		++beg;

	if (beg == v.end())
		cout << "All nums are positive!" << endl;
	else
		cout << "There is negative num!" << endl;

	/*
	 * for loop
	 */

	// the expressoin of range for statement can be a braced initializer list, an array,
	// or an object of a type such as vector or string that has begin and end members that
	// return iterators 


	return 0;
}