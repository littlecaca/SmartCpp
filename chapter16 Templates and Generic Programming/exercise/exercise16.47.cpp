#include <iostream>
#include <utility>

template <typename FT, typename AT1, typename AT2>
void flip(FT fcn, AT1 &&a1, AT2 &&a2)
{
    fcn(std::forward<AT1>(a1), std::forward<AT2>(a2));
}

int main(int argc, char const *argv[])
{
    int i = 9;
    auto fcn = [](int &a, int &&b) { a = a + b; b = b - a; };
    flip(fcn, i, 8);
    std::cout << i << std::endl;
    return 0;
}
