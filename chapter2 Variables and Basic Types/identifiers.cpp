#include <iostream>

/*
 * The identifiers we define in our own programs may not
 * contain two consecutive underscores, nor can an identifier
 * begin with an underscore followed immediately by an uppercase
 * letter. In addition, identifiers defined outside a function
 * mat not begin with an underscore.
 * 
 * For example, the bellow definitions is illegal:
 * int i__number;
 * int _Num;
 * int _globalVariable;
 */

int _;	// ok
// int 1_or_2 = 2;	// error: can't begin with decimal
int l_or_2 = 2;

int main(int argc, char const *argv[])
{
	std::cout << _ << std::endl;
	std::cout << l_or_2 << std::endl;
	std::cout << "Success" << std::endl;

	return 0;
}