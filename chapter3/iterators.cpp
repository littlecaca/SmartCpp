#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
 * Iterators
 * 
 * All of the library containers have iterators, but only a few of them
 * support the subscript operator. Technically speaking, a string is not
 * a container type, but string supports many of the container operations.
 *
 * A valid  iterator either denotes an element or denotes a position one
 * past the last element in a container.
 *
 *
 * Generic Programming
 *
 * C++ programmers use != rather than < in loops as a matter of habit. This
 * coding style applies equally well to various kinds of containers provided
 * by the library. Only a few library types have the subscript operator. Similarly
 * all of the library containers have iterators that define the == and != operators.
 *
 *
 * Iterator Types
 *
 * vector<int>::iterator it;
 * vector<int>::const_iterator it2;
 * string<int>::iterator it3;
 * string<int>::const_iterator it4;
 *
 *
 * Iterator Arithmetic
 *
 * Iterators for string and vector support additional operations that can move
 * multiple elements at a time. They also support all the relational operators.
 * These results must denotes elements in, or one past the end of, the same container. 
 *
 * iter + n
 * iter - n
 * iter1 += n
 * iter1 -= n
 * iter1 - iter2  the result type is a signed integral type named difference_type.
 * >, >=, <, <=
 */

int main(int argc, char const *argv[])
{
	vector<int> intvec(10, 8);

	auto i1 = intvec.begin(), i2 = --intvec.end();
	
    while (i1 != i2)
        cout << *i1++ << " ";
    cout << *--i2 << endl; 
	
    // to let us ask specifically for the const_iterator type, the new standard
    // introduce two new functions named cbegin and cend:
    auto i3 = intvec.cbegin();

    // combining dereference and member access
    vector<string> strvec(3, "hello");
    auto i4 = strvec.cbegin();
    cout << (*i4).size() << endl;
	return 0;
}