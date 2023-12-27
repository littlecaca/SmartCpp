#include <iostream>
#include <string>
#include <functional>
#include <map>

inline bool less(int lhs, int rhs) {
    return lhs < rhs;
}

int main(int argc, char const *argv[])
{
    std::map<std::string, std::function<int(int, int)>> ops = {
        {"add", std::plus<int>()},
        {"subtract", std::minus<int>()},
        {"multiply", std::multiplies<int>()},
        {"divid", std::divides<int>()},
        {"modulus", std::modulus<int>()},
        {"less", less},

    };
    std::cout << ops.at("modulus")(8, 3) <<std::endl;

    return 0;
}
