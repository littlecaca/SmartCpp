#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char const *argv[])
{
	vector<int> intvec{1, 2, 3, 4, 5, 5, 6, 7, 8, 10};

	for (auto it1 = intvec.begin(), it2 = intvec.end();
		it1 != it2; it1++) {
		*it1 *= *it1;		
		cout << *it1 << " ";
	}
	cout << endl;


	return 0;
}