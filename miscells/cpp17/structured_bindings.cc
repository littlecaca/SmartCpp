#include <utility>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::pair<int, int> p;
    std::tuple<int, double, long long> t1{12, 32.3, 123343423};

    auto [a, b] = p;
    auto [c, d, e] = t1;

    std::cout << a << "\t" << b << std::endl;
    std::cout << c << "\t" << d << "\t" << e << std::endl;
    return 0;
}
