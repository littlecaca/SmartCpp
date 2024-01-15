#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
	string line;
	string::size_type s1 = 0, s2 = 0;
	cout << "Input a string:" << endl;
	getline(cin, line);
	
	if (line.size() == 0) {
		cout << "There is no input" << endl;
		return -1;
	}


	while (s2 != line.size()) {
		if (!ispunct(line[s2])) {
			cout << line[s2];
			char temp = line[s2];
			line[s2] = line[s1];
			line[s1] = temp;
			s1++;
			
		}
		s2++;
	}

	cout << endl;

	return 0;
}