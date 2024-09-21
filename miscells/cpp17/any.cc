#include <any>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::any one;

    one = 12;
    int val = std::any_cast<int>(one);
    std::cout << val << std::endl;
    return 0;
}
