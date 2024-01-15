

/*
 * The most common technique for making it safe to include
 * a header multiple times relies on the preprocessor.
 * 
 * Header Guards
 *
 * Preprocessor variable names do not respect C++ scoping rules
 */

#ifndef SALES_DATA_H
#define SALES_DATA_H	// header guards variable

#include <string>

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.;
    short rate{0};
    short count = {0};
};

#endif