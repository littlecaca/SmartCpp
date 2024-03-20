#include <string>
#include "..\..\chapter7 Classes\adt.h"
#include <unordered_set>
#include <iostream>

namespace std {
    template <> struct hash<Sales_data>
    {
        typedef size_t result_type;
        typedef Sales_data argument_type;

        size_t operator()(const Sales_data &s) const 
        {
            return hash<string>()(s.bookNo) ^
                   hash<double>()(s.revenue) ^
                   hash<int>()(s.units_sold);
        }
    };
}

int main(int argc, char const *argv[])
{
    std::unordered_set<Sales_data> sales;
    sales.insert(Sales_data("ssss", 23, 99));
    sales.insert(Sales_data("rrrr", 32, 77));
    sales.insert(Sales_data("rrrr", 32, 77));
    sales.insert(Sales_data("rrrr", 32, 77));
    std::cout << sales.size() << std::endl;
 
    return 0;
}
