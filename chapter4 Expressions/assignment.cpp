#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	/*
	 * The result of an assignment is its left-hand operand, which
	 * is an lvalue.
	 *
	 *
	 * Assignment Is Right Associative
	 *
	 * 
	 * Compound Assignment Operators
	 *
	 * (When we use the compound assignment, the left-hand operand
	 * is evaluated only once. If we use an ordinary assignment, that operand
	 * is evaluated twice.)______on my machine, the two ways are completely equal___
	 *
	 *
	 * Use The Postfix Operators Only When Necessary
	 *
	 * The prefix version avoids unnecessary work. The postfix operator
	 * must store the original value so that it can return the unincremented
	 * value as its result, but the prefix operator don't need to do that.
	 *
	 *
	 * Brevity Can Be A virtue
	 *
	 * The succinct "*iter++" is easier and less error-prone than "*iter; ++iter"
	 */

	int n, m;
	n = m = 7;		// m = 7, n = 7
	(n = 1) = 8;	// n = 8
	std::cout << n << std::endl;

	// Initializer List
	// m = {3.14};	// error: narrowing conversion
	// m = {3, 4};	// error: fot built-in types, the list may contain at most one value
	std::vector<int> vi;
	vi = {2, 3, 4};	// ok
	// regardless of the type of the left-hand operand, the initializer list may be empty
	n = {};			// ok: value-initialized

	int *ptr2 = NULL;
	int *ptr = nullptr;
	if (ptr == 0 && ptr2 == 0)
		std::cout << "yes" << std::endl;
	
	
	return 0;
}