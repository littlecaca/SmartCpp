#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	int m = 3, n = 6;

	// error: the `4` is not lvalue, so the conditional operator yields an rvalue.
	// (21 > 11? m : 4) = 7;	

	// ok, both the `m` and `n` are lvalue, so the conditional operator yields an lvalue
	(21 > 11? m : n) = 7;	

	// nested conditional operations
	// it is right associative
	int grade = 91;
	std::string finalgrade = grade >= 90 ? "high pass" : grade < 60? "fail" : "pass";
	std::cout << finalgrade << std::endl; 
	return 0;
}