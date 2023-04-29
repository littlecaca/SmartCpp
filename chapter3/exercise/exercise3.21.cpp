#include <iostream>
#include <string>
#include <vector>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
	vector<int> v1{99};
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{10};
	vector<int> v5{10, 42};
	vector<string> v6{10};
	vector<string> v7{10, "hi"};

	vector<vector<int>> intvecs{v1, v2, v3, v4, v5};
	// vector<vector<int>> intvecs;
	// intvecs.push_back(v1);
	// intvecs.push_back(v2);
	// intvecs.push_back(v3);
	// intvecs.push_back(v4);
	// intvecs.push_back(v5);


	/*
	 * Question: Why don't containers hold references of objects but the obejcts themselves?
	 */
	intvecs[0].push_back(1);
	cout << "size of intvecs[0]:" << intvecs[0].size() << endl;
	cout << "size of v1:" << v1.size() << endl;

	for (auto iv : intvecs) {
		for(auto it1 = iv.cbegin(), it2 = iv.cend();
			it1 != it2; it1++)
			cout << *it1 << " ";
		cout << "size:" << iv.size() << endl; 
	}

	vector<vector<string>> strvecs{v6, v7};

	for (auto sv : strvecs) {
		for (auto it1 = sv.cbegin(), it2 = sv.cend();
			it1 != it2; it1++)
			cout << *it1 << " ";
		cout << "size:" << sv.size() << endl;
	}

	return 0;
}