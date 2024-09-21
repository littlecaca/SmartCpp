#include <iostream>

int main(int argc, char const *argv[])
{
    auto func = [](auto a, auto b) { return a * b; };
    int x = 12;
    double y = 132.3243;
    std::cout << func(x, y) << std::endl;
    
    return 0;
}
