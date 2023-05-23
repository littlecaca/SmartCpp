#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
 * A string is a variable-length sequence of characters.
 *
 *
 * Initialization
 *
 * When we initialize a variable using =, we are asking the compiler
 * to `copy initializ` the object by copying the initializer.
 * Otherwise, when we omit the =, we use `direct initialization`.
 *
 * Operations on strings
 * 
 * getline(is, s) Reads a line of input from is into s. Returns is
 * s.empty() Returns bool type
 * s.size()	Returns string::size_type
 * s[n]	Returns a reference to the char at position n in s
 * <, <=, >, >= Comparisions are case-sensitive and use dictionary ordering
 * 
 * Why does the s.size() return string::size_type type?
 * 
 * The string class defines several companion types which make it possible
 * to use the library types in a machine-independent manner. The size_type
 * is one of these companion types.
 *
 */

int main(int argc, char const *argv[])
{
	// initialization
	string s1;			// default
	string s2 = s1;		// s2 is a copy of s1
	string s3 = "hiya";	// s3 is a copy of the string literal
	string s4(10, 'c'); // s4 is cccccccccc, direct form of initialization

	// using the copy form of initialization by explicitly creating
	// `a (temporary) object` to copy
	string s5 = string(10, 'c');
	// the above definition is as if the fllowing:
	string temp(10, 'c');
	string s6 = temp;

	string s7(s6);		// s7 is a copy of s6
	
	// it reads characters until the next whitespace character is encounterd
	cin >> s1;
	cout << s1 << endl;

	cout << "getline:" << endl;
	// getline will not read the \n in the end of the input
	while (getline(cin, s2))
		if (!s2.empty()) {
			cout << s2 << endl;
			cout << "size: " << s2.size() << endl;
		}

	string::size_type size = s1.size();
	auto size2 = s1.size();

	if (size < -1)
		// True
		cout << "size < -1" << endl;
	else
		cout << "size >= -1" << endl;

	/*
	 * The string library lets us convert both character literals and
     * character string literals to strings
     */
	string s8 = "Hello", s9 = "World";
	string s10 = s8 + ", " + s9 + '\n';
	
	// range-based for
	for (auto c : s10)
		cout << c << endl;

	// can't add string literals
	// string s11 = "Hello" + " , " + s9 + '\n';	// error
	

	// the string object be changed locally
	string st1("genius");
	cout << (long long)&st1 << endl; 
	string &rst = st1;
	st1 = "ordinary yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy";
	cout << (long long)&st1 << endl;
	cout << rst << endl;

	return 0;
} 