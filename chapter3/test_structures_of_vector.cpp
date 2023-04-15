#include <vector>
#include <string>

using std::string;
using std::vector;

int main(int argc, char const *argv[])
{	
	vector<int> nums1{1, 2, 3};
	vector<int> nums2;
	// int u = nums2[0];	
	
	string s1 = "you";
	string s2("and");

	vector<string> sv{s1};
	sv.push_back(s2);	

	/*
	 * Results of Experiments
	 *
	 * The vectors hold pointers to objects, which is not consecutive in
	 * memory, and these objects is copied from the initializers. The elements
	 * carried in vectors is not the objects used as these vectors' initializers.
	 *
	 * As to the string, they just holds the the pointer to the first character, and
	 * these characters are stored consecutively.
	 */

	return 0;
}