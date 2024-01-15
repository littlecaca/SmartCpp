#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
	string text, line;
	
	getline(cin, line);
	text += line;
	while (getline(cin, line)) {
		if (line.size() > 0) {
			text += " " + line;
		}
	}

	if (text.size() == 0) {
		cout << "no text!" << endl;
		return -1;
	}
	

	text += "\n";
	cout << text;
	return 0;
}