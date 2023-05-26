#include "Sales_data.h"
#include <iostream>


std::istream &read(Sales_data &i1) {
    std::cout << "Please input bookno, revenue, units_sold:" << std::endl;
    return std::cin >> i1.bookNo >> i1.revenue >> i1.units_sold;
}

std::ostream &print(const Sales_data &i1) {
    double price = i1.revenue / i1.units_sold;
    std::cout << "(" << i1.bookNo << ", "
              << i1.revenue << ", " << i1.units_sold
              << ")";
    return std::cout << " price = " << price;
}

void combine(Sales_data &total, const Sales_data &i1) {
    total.revenue += i1.revenue;
    total.units_sold += i1.units_sold;
}