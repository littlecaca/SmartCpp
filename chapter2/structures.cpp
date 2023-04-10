#include <iostream>
#include <string>
#include "Sales_data.h"

/*
 * if we use a class a class in several diferent files, the class's
 * definition must be the same in each file.
 */

// struct Sales_data
// {
// 	std::string bookNo;
// 	// we can't specify an in-class initializer 
// 	// inside parentheses or curly braces
// 	unsigned units_sold = 0;	// C++11: in-class initializer
// 	double revenue = 0.;	
// };	// expected ‘;’ after struct definition

int main(int argc, char const *argv[])
{
	Sales_data data1, data2;

	double price;
	// read data
	std::cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = price * data1.units_sold;
	std::cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = price * data2.units_sold;

	if (data1.bookNo == data2.bookNo) {
		unsigned total_sold = data1.units_sold + data2.units_sold;
		double total_revenue = data1.revenue + data2.revenue;
		std::cout << total_sold << std::endl;
		std::cout << total_revenue << std::endl;

		if (total_revenue > 0)
			std::cout << total_revenue / total_sold << std::endl;
		else
			std::cout << "no sales" << std::endl;
		
		return 0;
	} else {
		std::cout << "The two transactions must have the same ISBN."
				  << std::endl;
		return -1;
	}
}

