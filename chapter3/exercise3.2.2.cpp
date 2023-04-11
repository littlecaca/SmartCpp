#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
	string text, line;
	if (getline(cin, text)) {
		while (getline(cin, line)) {
			if (line.size() > 0) {
				text += " " + line;
			}
		}
	} else {
		cout << "no text!" << endl;
		return -1;
	}

	text += "\n";
	cout << text;
	return 0;
}