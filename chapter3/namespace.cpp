#include <iostream>

// each using declaration introduces a single namespace member
using std::cin;
using std::cout;
using std::endl;
using std::cin;		// duplicated, but ok

/*
 * The using should not apear in header files,
 * beacuse a program including that header may not
 * intend to use the specified library name, which
 * possibly leads to name conficts.
 */
int main(int argc, char const *argv[])
{
	cout << "namespace" << endl;	
	return 0;
}