#include <iostream>


/*
 * More generally, a declaration is a base type
 * fllowed by a list of declarators. Each declarator
 * names a variable and gives the variable a type
 * that is related to the base type.
 *
 * C++ has several compound types, two of which are
 * references and poninters.
 * 
 * References
 * A references defines an alternative name for an object.
 * When we define a reference, instead of copying the initializer's
 * value, we BIND the reference to its initializer.
 * A reference is just another name for an already existing object.
 * 
 * Pointers
 * It has been learned in c language.
 * The three kinds of valid pointer values:
 * 1. pointers to any object
 * 2. pointers to one past the end of an object
 * 3. null pointers
 * for 2 and 3, we canot access the objects they point to.
 * 
 * Void * Pointers
 * There are only a limited number of operations we can do with a void* pointer:
 * 1. compare it to another void* pointer
 * 2. pass it to or return it from a function
 * 3. assign it to another void* pointer
 *
 * Advice: Initialize All Pointers
 * If possible, define a pointer only after the object to which it
 * should point has been defined.
 */
int main(int argc, char const *argv[])
{
	int ival = 1024;
	int &refVal = ival;
	// int &refVal2;	// error: a reference must be initialized
	int &refVal2 = refVal;	// ok
	int ival2 = refVal2;	// ok
	int *pi = &refVal;		// ok
	// a reference may be bound only to an object, not to a literal or
	// to the result of a more general expression.
	// int &pi = 3.14;		// error: initializer must be an object
	// double &pi = ival;	// error: initializer must be an double object here

	std::cout << ival2 << std::endl;
	std::cout << *pi << std::endl;
	int *p1 = nullptr;

	// We can use a pointer in a condition
	if (p1) 
		std::cout << "YES" << std::endl;

	// Because a pointer is an object, we can define a reference to a pointer
	int j = 42;
	// int *&refVal3 = &i;	// error: a initializer for references must be an object 
	int *pj;
	int *&refPj = pj;
	refPj = &j;
	*refPj = 0;
	std::cout << "The value of j:" << j << std::endl;

	int nums[5][4];
	int (*nums2)[4] = nums;
	std::cout << sizeof *nums2 << std::endl;
	// a reference to array
	auto &nums3 = nums;
	decltype((nums)) nums4 = nums;

	std::cout << "The sizeof nums3: " << sizeof nums3 << std::endl;
	std::cout << "The sizeof nums4: " << sizeof nums4 << std::endl;
	
	return 0;
}