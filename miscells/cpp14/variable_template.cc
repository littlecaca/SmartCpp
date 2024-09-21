#include <iostream>


template <typename T>
constexpr T pi = T(3.1415926535897932385);

int main(int argc, char const *argv[])
{
    std::cout << pi<int> << std::endl;
    std::cout << pi<float> << std::endl;
    return 0;
}
