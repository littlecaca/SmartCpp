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

	return 0;
}