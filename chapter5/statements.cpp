#include <iostream>

int main(int argc, char const *argv[])
{
	/*
	 * e
	 */

	int ival = 5;

	// expression statement
	ival + 5;

	// null statement
	;	// should be ommited 

	// compound statement
	int sum = 0;
	while (ival < 10)
		sum += ival;
	++ival;

	
	// statement scope

	while (int i = ival--)
		++sum;
	// i = 4; // error: i is not defined


	// dangling else: means that how do we know to which `if` a given `else` belongs?
	
	// wrong version
	if (ival % 10 >= 3)
		if (ival % 10 < 7)
			std::cout << "+" << std::endl;
	else 	// the `else` matches the closed `if`
 		std::cout << "-" << std::endl;

 	// right version
	if (ival % 10 >= 3) {
		if (ival % 10 < 7)
			std::cout << "+" << std::endl;
	} else 
 		std::cout << "-" << std::endl; 	

	return 0;
}