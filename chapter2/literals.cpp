#include <iostream>


int main(int argc, char const *argv[])
{
	int m = 19;		// decimal
	int n = 023;	// octal
	int k = 0x13;	// hexadecimal
	std::cout << n << "\t" << m << "\t" << k << std::endl;

	// scientific notation
	std::cout << 3.14159e0 << std::endl;

	/*
	 * Escape Sequences
	 * octal \nnn only the first three are associated with the \.
	 * hexadecimal \xnnnn... uses up all the hex digits fllowing it.
	 */
	std::cout << "\141 \x4d likes a man." << std::endl;
	
	/*
	 * Specifying the Type of a Literal
	 * 
	 * A literal with a suffix of UL will be either unsigned long or
	 * unsigned long long, depending on whether its value fits in unsigned long.
	 * 	Prefix	Meaning					Type
	 *	u 		Unicode 16 character	char16_t
	 *	U  		Unicode 32 character	char32_t
	 *	L 		wide character			wchar_t
	 * 	u8 		utf-8(string literals only) char
	 */
	char16_t s0 = u'你';			// Unicode 16 character
	wchar_t s1 = L'a';			// wide character literal, type is wchar_t
	const void *s2 = u8"你好";	// utf-8 string literal
	42ULL;
	1E-3F;
	3.14159L;

	std::cout << s0 << std::endl;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << "你好" << std::endl;

	// int test = 09;	// This is an error!
	// std::cout << test << std::endl;

	std::cout << "\62\x9\115" << std::endl;
	return 0;
}


