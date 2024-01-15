#include <iostream>

// To obtain a declaration that is not also a definition,
// we add the extern keyword
extern int count;
extern double price;
// if we define another count, this wll lead to an error in link stage
// int count = 21;	// error
// int count;		// error
// And if we provide an initializer while adding an extern keyword,
// this also leads to an error(not in global scope)

/*
 * Variables must be defined exactly once but can be declared many times.
 */

int main(int argc, char const *argv[])
{	
	price += 1;
	std::cout << "The value of count is " << count << std::endl;
	std::cout << "The price is " << price << std::endl;
	return 0;
}