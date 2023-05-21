#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
	string last, cur, maxs;
	int count, max = 0;

	if (cin >> cur) {
		count = 1; max = 1; maxs = last = cur;
		while (cin >> cur) {
			if (cur == last)
				max = ++count > max ? maxs = cur, count : max;
			else
				count = 1;
			last = cur;
		}
		max = max > count ? max : count;
		cout << maxs << ": " << max << endl;
	}

	// full empty init-statement, condition, expression
	for (;;) {
		if (max-- == 0)
			break;
	}

	return 0;
}