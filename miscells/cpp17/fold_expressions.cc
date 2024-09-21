#include <iostream>

template <typename ...Args>
int sum(Args ...args)
{
    // uniary right fold
    return (args + ...);
}

int main(int argc, char const *argv[])
{
    std::cout << sum(1, 2, 3, 4, 5) << std::endl;
    return 0;
}
