#include <iostream>
#include <cctype>
#include <string>

// Just the class object need to use namespace,
// the function like ones in C don't have to.
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
 * isalnum(c)
 * isalpha(c)
 * iscntrl(c)
 * isdigit(c)
 * isgraph(c)	true if c is not a space but is printable
 * islower(c)
 * isupper(c)
 * isprint(c)	true if c is a space or a character
 * ispunct(c)
 * isspace(c)
 * isxdigit(c)
 * tolower(c)
 * toupper(c)
 */

int main(int argc, char const *argv[])
{
	string line;
	cout << "Input a string:" << endl;
	getline(cin, line);
	if (line.empty()) {
		cout << "There is no input!" << endl;
		return -1;
	}


	decltype(line.size()) punct_cnt = 0;
	for (char &c : line)
		if (isalnum(c)) {
			punct_cnt++;
			c = 'X';
		}

	cout << punct_cnt << " characters in " << line << endl;

	for (auto &c : line)
		c = tolower(c);

	// lower the first char
	/*
	 * The subscript operator
	 * If the index has a signed type, its value will converted to
	 * the unsigned type that string::size_type represents.
	 * 
	 * Subscripts Are Unchecked
	 * When we use a subscript, we must ensure that the subscript is in
	 * range. The library will not to check the value of an subscript.
	 */
	if (isalpha(line[0])) line[0] = toupper(line[0]);
	for (decltype(line.size()) index = 1; index != line.size()
		; index++) {
		if (isspace(line[index-1]) && isalpha(line[index]))
			line[index] = toupper(line[index]);
	}

	cout << line << endl;

	string test;
	cout << test[0];

	return 0;
}