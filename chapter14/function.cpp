#include <functional>
#include <map>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/*
 * Note
 * The function-call operator must be a member function. A class may define
 * multiple versions of the call operator, each of which must differ as to
 * the number or types of their parameters.
 *
 *
 *
 * Lambdas Are Function Objects
 *
 * By default, lambdas may not change their captured variables. As a result,
 * by default, the function-call operator in a class generated from a lambda
 * is a const member function. If the lambda is declared as mutable, then
 * the call operator is not const.
 *
 *
 *
 * Classes Representing Lambdas with Captures
 *
 * When a lambda captures a variable by reference, it is up to the
 * program to ensure that the variable to which the reference exists
 * when the lambda is executed. Therefore, the compiler is permitted to use
 * the reference directly without storing that reference as a data member
 * in the generated class.
 *
 * Classes generated from a lambda expression have a deleted default constructor,
 * deleted assignment operators, and a default destructor.
 *
 * 
 * 
 * Library-Defined Function Objects
 * 
 * The standard library defines a set of classes that represent the arithmetic,
 * relational, and logical operators.
 * 
 * Library Function Objects
 * 
 * Arithmetic		Relational			Logical
 * 
 * plus<>			equal_to<>			logical_and<>
 * minus<>			not_equal_to<>		logical_or<>
 * multiplies<>		greater<>			logical_not<>
 * divides<>		greater_equal<>
 * modulus<>		less<>
 * negate<>			less_equal<>
 * 
 * 
 * One important aspect of these library function obejcts is that the 
 * library guarantees that they will work for pointers.
 * 
 * It is worht nothing that the associative containers use less<key_type>
 * to order their elements. As a result, we can define a set of pointers
 * or use a pointer as the key in a map without specifying less directly.
 * 
 * 
 * 
 * Callable Objects and function
 * 
 * C++ has serval kinds of callable obejcts: functions and pointers to
 * functions, lambdas, objects created by bind, and classes that overload
 * the function-call operator.
 * 
 * Two callables obejcts with different types may share the same call
 * signature.
 * 
 * 
 * 
 * The Library function Type
 * 
 * Operations on function
 * 
 * function<T> f;	f is a null function object that can store callable obejcts
 * 					with a call signature that is equivalent to the function type T
 * function<T> f(obj);	Store a copy of the callable obejct obj in f.
 * f				Use f as a condition; true if f holds a callable object; false otherwise;
 * f(args)
 * 
 * Types defined as members of function<T>
 * 
 * result_type		The type returned by this function type's callable object.
 * argument_type	Types defined when T has exactly one or two arguments.
 * first_argument_type	
 * second_argument_type
 * 
 * 
 * 
 * Overloaded Functions and function
 * 
 * We cannot (directly) store name of an overloaded function in an obejct
 * of type function, otherwise the compiler cannot make sure which function to use.
 * 
 * Note
 * The function class in the new library is not related to classes
 * named unary_function and binary_function.
 */

// exercise14.34
class IfThen {
  public:
	int operator()(bool b, int i1, int i2) { return b ? i1 : i2; }
};

// exercise14.35
class ReadString {
  public:
	ReadString(std::istream &is) : is(is) {}
	std::string operator()();

  private:
	std::istream &is;
};

std::string ReadString::operator()() {
	std::string line;
	getline(is, line);
	return line;
}

int add(int i, int j) { return i + j; }
int add(std::string &s1, std::string &s2) { return 1; }


int main(int argc, char const *argv[]) {
	// IfThen it;
	// std::cout << it(true, 2, 3) << std::endl;

	ReadString rs(std::cin);
	// std::cout << rs() << std::endl;
	// std::cin.setstate(std::cin.failbit);
	// std::cout << rs() << std::endl;

	// std::cin.clear();
	// std::string s = rs();
	// std::cout << s << std::endl;

	// exercise14.36
	std::vector<std::string> vs;
	while (true) {
		std::string line = rs();
		if (line.size()) {
			vs.push_back(line);
		} else
			break;
	}

	for (const auto &line : vs)
		std::cout << line << std::endl;


	int s = 1;
	auto sz = [s](const std::string &a) mutable { std::cout << s << std::endl; };
	sz("Nihao");

	std::plus<int> intAdd;
	std::negate<int> intNegate;
	std::modulus<int> intModulus;

	// ok: the elements in as will be sorted by address in memory
	std::array<const char *, 10> as = {"you", "are", "really"};
	// library guarantees that less on pointer types is well defined
	std::sort(as.begin(), as.end(), std::less<const char *>());
	for (auto pc : as) {
		if (pc)
			std::cout << pc << std::endl;
	}

	// error: conversion from <unresolved overloaded function type> to non-scalar type
	// 'std::funciton<int(int, int)>
	// std::function<int(int, int)> f = add;

	// ok
	int (*fp)(int, int) = add;
	std::function<int(int, int)> f = fp;
	
	return 0;
}
