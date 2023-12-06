#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

#define PP(x) std::cout << #x << std::endl;

int main(int argc, char const *argv[])
{
	std::string name = "sad";
	PP(you are really a good man!!! woc);

	unordered_map<int, int, hash<int>, equal_to<int>> t();
	return 0;
}
