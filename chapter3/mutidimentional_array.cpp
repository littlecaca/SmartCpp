#include <iostream>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
	/*
	 * Using a Range for with Mutidimentional Arrays
	 * 
	 * 
	 */

	int int_arr[3][4] = {
		{1, 2, 3, 4},
		{5, 6},
		{7, 8}
	};

	// the outer loop variable must be a reference to avoid the normal array
	// to pointer conversion. Otherwise, the inner loop variable will be invalid,
	// because the `row` is not iterable as a pointer to int.
	for (const auto &row : int_arr) {
		for (auto &col: row)
			cout << col << " ";
		cout << endl;
	}

	// another way
	for (int (*row)[4] = int_arr; row != int_arr + 3; row++) {
		for (int *col = *row; col != *row + 4; col++)
			cout << *col << " ";
		cout << endl;
	}

	// another more secure way
	for (auto row = int_arr; row != int_arr + 3; row++) {
		for (auto col = *row; col != *row + 4; col++)
			cout << *col << " ";
		cout << endl;
	}

	// another more secure and convenient way
	for (auto row = std::begin(int_arr); row != std::end(int_arr); row++) {
		for (auto col = std::begin(*row); col != std::end(*row); col++)
			cout << *col << " ";
		cout << endl;
	}

	// another more readable way
	using int_array = int[4];
	// //equals
	// typedef int int_array[4];
	for (int_array *row = int_arr; row != int_arr + 3; row++) {
		for (int *col = *row; col != *row + 4; col++)
			cout << *col << " ";
		cout << endl;
	}

	return 0;
}