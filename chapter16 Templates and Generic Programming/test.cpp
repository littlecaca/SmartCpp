#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

#define PP(x) std::cout << #x << std::endl;

template <typename T>
void func(T &&t) {}

template <typename T>
void func(T t) {}

int main(int argc, char const *argv[])
{
	std::string name = "sad";
	PP(you are really a good man!!! woc);

	// func(21);	// more than one instance of overloaded function "func" matches the argument list:
	unordered_map<int, int, hash<int>, equal_to<int>> t();
	return 0;
}
