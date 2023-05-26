#include <string>
#include <iostream>

#ifndef SALES_DATA_H
#define SALES_DATA_H

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0; 
};

std::istream &read(Sales_data &);
void combine(Sales_data &, const Sales_data &);
std::ostream &print(const Sales_data &);

#endif