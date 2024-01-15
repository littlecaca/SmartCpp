#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
	int num;
	if((cin >> num) && num !=42) {
		cout << num;
		while ((cin >> num) && num != 42)
			cout << " " << num;	
	}
	cout << endl;
	return 0;
}