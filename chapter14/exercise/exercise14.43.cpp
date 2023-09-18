#include <iostream>
#include <iterator>

using std::begin;
using std::end;

int main(int argc, char const *argv[])
{
    int ai[] = {1, 2, 32, 4, 7};
    auto first = begin(ai);
    auto last = end(ai);
    int given = 56;
    auto mod = std::modulus<int>();
    
    for (auto iter = first; iter != last; ++iter)
        if (mod(given, *iter) == 0)
            std::cout << *iter << std::endl;

    return 0;
}
