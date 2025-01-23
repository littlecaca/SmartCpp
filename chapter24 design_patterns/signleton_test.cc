#include <iostream>
#include "singleton.h"


int main()
{
    int &i = Singleton<int>::getInstance();

    i = 12;

    std::cout << i << std::endl;
    return 0;
}