#include <iostream>
#include <string>


int main(int argc, char const *argv[])
{
	// a variable-length sequence of characters
	std::string book("0-201-78345-X");

	std::cout << book << std::endl;	


	/*
	 * Initialization is not assignment.
	 */

	// For example, you can't mix the bellow two statements.
	int nums[][12] = {
		{1, 2, 4},
		{1, 3, 5},
	};

	int (*p)[12] = nums;

	std::cout << p[0][1] << std::endl;

	struct items {
		int count;
		const char *name;
		long long id;
		double price;
	};

	typedef struct items item;

	item i1 = {1, "sisokaffer", 213, 32.23};
	// This can be legal in c++
	i1 = {2};

	std::cout << i1.count << "\t" << i1.name << "\t" << i1.id
			  << "\t" << i1.price << std::endl;



	return 1;
}