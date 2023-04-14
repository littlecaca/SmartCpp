#include <iostream>
#include <vector>


/*
 * Iterators
 * 
 * All of the library containers have iterators, but only a few of them
 * support the subscript operator. Technically speaking, a string is not
 * a container type, but string supports many of the container operations.
 *
 * A valid  iterator either denotes an element or denotes a position one
 * past the last element in a container.
 */

int main(int argc, char const *argv[])
{
	vector<int> intvec(10, 8);

	auto i1 = intvec.begin(), i2 = intvec.end();
	
	
	return 0;
}