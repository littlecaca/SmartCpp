#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
	/*
	 | Implicit Conversions
	 | 
	 |------Arthmetic Conversions
	 |
	 |			In arithmetic and relational expressions with operands of mixed types, the types
	 |		are converted to a common type.
	 | 		(int -> long -> long long -> float -> double -> long double)
	 |		(signed -> unsigned)
     |			If type of the unsigned operand is  the same as or larger than that of the signed operand,
     |		the signed operand is converted to unsigned. For example, `long` x `unsigned int` (assuming
     |		`long` and `int` have the same size), then `long` will be converted to `unsigned int`.
     |			If all possible values in the unsigned type fit in the larger type, then
     |		the unsigned operand is converted to the signed type. 		
     |
     |------Integral Promotions
     |
   	 |			Values of integral types smaller than int are first promoted to an 
   	 |		appropriate larger integral type. The types bool, char, signed char,
   	 |		unsigned char, short, and unsiged short are promoted to int if all possible values
   	 |		of that type fit in an int. Otherwise, the value is promoted to unsigned int.
   	 |		The larger char types(wchar_t, char16_t, and char32_t)are promoted to the smallest
   	 |		type of int, unsigned int, long, unsigned long, long long, or unsigned long long in
   	 |		which all possible values of that chatacter type fit.
     |
     |------Assignment Conversions
     |
     |			In initializations and assignments, the initializer(except list initializer) to right-hand
     |		operand is converted to the type of the variable.
     | 
     |------Defalut arguments Conversions
     |
     |			()
	 | 
	 |------Condition Conversions
	 |		
	 |			In conditions, nonbool expressions are converted to bool.
	 |
	 |------Array to Pointer Conversions	
	 |
	 |			This conversion is not performed when an array is used with decltype or as
	 | 		the operand od the addresss-of(&), sizeof, or typeid. The conversion is also omitted
	 |		when we initialize a reference to an array.
	 |
	 |------Function Conversions
	 |
	 |			The function name will be converted a pointer to that function when it is used in expression.
	 |
	 |------Pointer Conversions
	 |
	 |			A constant integral value of 0 and the literal nullptr can be converted to any pointer type;
	 |		A pointer to any nonconst type can be converted to void *, and a pointer to any type can be
	 |		converted to a const void*
	 |
	 |------Conversions Defined by Class Types  
	 */

	int m = 1;
	m = 3.1;

	cout << m << endl;
	int ival;
	unsigned uival;
	short sval;
	char cval;
	long lval;
	unsigned short usval;
	// examples
	3.1415926L + 'a';	// (char)'a' -> int -> long double
	sval + cval; 		// sval and cval promoted to int
	usval + ival;		// promotion depends on the size of unsigned short and int
	uival + lval;		// conversion depends on the size of unsigned int and long


	int nums[][2] = {1, 2, 3};
	auto pn = nums;		// pn is an int (*)[2]
	cout << **pn << endl;

	int (*pn2)[2][2] = &nums;
	int (&rpn)[2][2] = nums;

	return 0;
}