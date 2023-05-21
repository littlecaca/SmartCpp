#include <iostream>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{	
	char vowels[] = {'a', 'e', 'i', 'o', 'u'};
	char alpha;
	int vowelCnt = 0;
	char last = 0;
	while (cin >> alpha && std::isalpha(alpha)) {
		if (alpha < 'a')
			alpha += 'a' - 'A';

		// match two-character sequences
		if (last == 'f')
			if (alpha == 'f' || alpha == 'l' || alpha == 'i') {
				++vowelCnt;
				last = 0;
				continue;
			}

		for (char c : vowels)
			if (alpha == c) {
				++vowelCnt;
				break;
			}
	
		last = alpha;
	} 

	cout << "The count of vowel: " << vowelCnt << endl;
	return 0;
}