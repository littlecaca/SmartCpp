#include "exercise14.2.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Sales_data s1, s2;
    std::cin >> s1 >> s2;
    std::cout << s1 << std::endl << s2 << std::endl;
    if (std::cin) {
        Sales_data s3 = s1 + s2;
        std::cout << s3;
    }
    
    
    return 0;
}
