#include <iostream>

int main(int argc, char const *argv[])
{
    if (int i = 12; i != 12)
    {
        std::cout << i << std::endl;
    }

    switch (int m = 12; m & 1)
    {
    case 1:
        std::cout << "m is odd" << std::endl;
        break;
    
    default:
        std::cout << "m is even" << std::endl;
        break;
    }
    return 0;
}
