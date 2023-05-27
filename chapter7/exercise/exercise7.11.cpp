#include "../adt.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Sales_data sale("123456", 234, 324.4);
    Sales_data sale2("123456");

    print(std::cout, sale) << std::endl;
    print(std::cout, sale2) << std::endl;
    return 0;
}
