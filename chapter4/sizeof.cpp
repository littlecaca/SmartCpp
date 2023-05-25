#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	/*
	 * sizeof don't evaluete its operand, so although 'p' is an invalid
	 * pointer, the 'sizeof *p' is fine.
	 *
	 *
	 * sizeof a string or a vector returns only the size of the fixed part of
	 * these types; it does not return the size used by the object's elements.
	 *
	 * Because sizeof returns a constant expression, we can use the result of a
	 * sizeof expression to specify the dimension of an array.
	 *
	 */

	short *p = nullptr;
	if (p == 0)
		std::cout << "p == 0" << std::endl;

	// it is ok to dereference p here
	std::cout << "the size of p:"<< sizeof *p << std::endl;
	std::cout << "the size of vector<int>::size_t: " << sizeof (std::vector<int>::size_type) << std::endl;

	return 0;
}