#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
	/*
	 * A label may not stand alone, it must precede a statement or another case label.
	 *
	 * It is illegal to jump from a place where a variable with an initialzer is out of
	 * scope to a place where that variable is in scope.
	 */
	char alpha;
	int vowelCnt = 0;
	while (cin >> alpha) {
		switch (alpha) {
			// case labels must be integral constant expressions
			// you need to make comments if you intentionally ommit the `break`
			case 'a':case 'e':case 'i':case 'o':case 'u':
				++vowelCnt;
				break;
			case '!':
				cout << "!!!" << endl;
			// it is useful to define a default label even if there is no work for the default case
			// , which indicates to subsequent readers that the case was considered
			default:
				cout << "\"" << alpha << "\"" << "not a vowel" << endl;
		}
	}
	cout << "the count of vowel: " << vowelCnt << endl;

	// the language does not allow us to jump over an initialization if the initialized variable is in
	// scope at the point to which control transfers.

	switch (alpha) {
		case 'a':
			// int i = 32;	// error: jump to case label; note:   crosses initialization of ‘int i’
		case 'b':
			// the `i` is in scope but it's may be uninitialized
		default:
			// the `i` is in scope but it's may be uninitialized
			cout << "over!" << endl;
	}

	switch (alpha) {
		case 'a': {
			// defining the variable inside a block, thereby ensuring that the variable is out of 
			// scope at the point of any subsequent label
			int i = 32;		// ok
		}
		case 'b':
		default:
			cout << "yes!" << endl;
	}

	return 0;
}