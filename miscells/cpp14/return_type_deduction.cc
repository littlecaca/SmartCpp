#include <iostream>

auto func(int x)
{ 
    return x * x;
}

int main(int argc, char const *argv[])
{
    std::cout << func(2) << std::endl;
    return 0;
}
