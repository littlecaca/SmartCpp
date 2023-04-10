#include <iostream>

int main(int argc, char const *argv[])
{
	int i = 0, &r = i;
	auto a = r;		// a is an int
	const int ci = i, &cr = ci;
	auto b = ci;	// b is an int
	auto c = cr;	// c is an int
	auto d = &i;	// d is an int *
	auto e = &ci;	// e is a const int *
	const auto f = ci;	// f is a const int
	auto &g = ci;	// g is a const int &



	std::cout << "a:" << a << std::endl;
	std::cout << "b:" << b << std::endl;
	std::cout << "c:" << c << std::endl;
	std::cout << "d:" << d << std::endl;
	std::cout << "e:" << e << std::endl;
	std::cout << "f:" << f << std::endl;
	std::cout << "g:" << g << std::endl;

	std::cout << "=========================" << std::endl;

	a = 42;		// ok
	b = 42;		// ok
	c = 42;		// ok
	// d = 42;	// invalid
	// e = 42;	// error
	// f = 42;	// error
	// g = 42;	// error


	std::cout << "a:" << a << std::endl;
	std::cout << "b:" << b << std::endl;
	std::cout << "c:" << c << std::endl;
	std::cout << "d:" << d << std::endl;
	std::cout << "e:" << e << std::endl;
	std::cout << "f:" << f << std::endl;
	std::cout << "g:" << g << std::endl;

	return 0;
}