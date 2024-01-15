#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


int main(int argc, char const *argv[])
{
	/*
	 * Generally, we can use a null-terminated character array anywhere
	 * that we can use a string literal:
	 * 1) we can use a null-ternimated character array to initialize or assign
	 * 	  a string.
	 * 2) we can use a null-ternimated character array as one operand(but not both operands)
	 *	  to the string addition operator or as the right-hand operand in the string compound
	 * 	  assignment(+=) operatior.
	 *
	 * There is a string member function named c_str that we can use to get the pointer of
	 * the character array, but the pointer points to const char.
	 *
	 *
	 * We can use an array to initilize a vector.
	 *
	 *
	 * Modern C++ progroms should use vectors and iterators instead of built-in
	 * arrays and pointers, and use strings rather than C-style array-based character strings.
	 */

	string s("Hello World");
	const char *sa = s.c_str();

	for (const char *p = sa; *p != '\0'; p++)
		cout << *p;
	cout << endl;

	s = "Hello C++";

	// any subsequet use of s that might change the value of s can invalidate this array.
	// so if you change the s, then call the s.c_str() to get sa again!
	for (const char *p = sa; *p != '\0'; p++)
		cout << *p;

	cout << endl;

	// To use an array to initialize a vector, we specify the address of the first element
	// and one past the last element that we wish to copy.
	int int_arr[] = {1, 2, 3, 4};
	vector<int> ivec(std::begin(int_arr), std::end(int_arr));

	for (auto n : ivec)
		cout << n;
	cout << endl;

	// see? the char array can be used like string literals anywhere
	char sentence[] = "you are genious!";
	string s2("WoW!"), s3 = s2 + " " + sentence;
	cout << s3 << endl;
	return 0;

}