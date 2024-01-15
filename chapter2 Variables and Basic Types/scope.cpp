/*
 * function scope: goto
 * 
 * Block Scope
 * Within the scope of the code block, and can be accessed
 * throughout the rest of the block.
 * 
 * Global Scope 
 * Outside any function, can be accessed throughout the program
 * 
 * declaration scope
 *
 *
 * Advice: Define Variables Where You First Use Them
 */

#include <iostream>

int num = 33;
int main(int argc, char const *argv[])
{
	int num = 2;
	// Names declared in the outer scope can be redefined in an inner scope.
	{

		int num = 4;
		std::cout << "The inner num:" << num << std::endl;
	}

	std::cout << "The outer num:" << num << std::endl;
	// When the scope operator has an empty left-hand side, it is
	// a request to fetch the name on the right-hand side from the
	// global scope.
	std::cout << "The global num:" << ::num << std::endl;
	return 0;
}