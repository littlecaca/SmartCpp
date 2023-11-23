#include <array>
#include <iostream>

template <typename Element, size_t Size>
std::ostream &print(std::ostream &os, Element (&array)[Size])
{
    os << "(";
    for (size_t i = 0; i != Size; ++i)
    {
        os << array[i] << ", ";
    }
    os << ")";
    return os;
}

int main(int argc, char const *argv[])
{
    int array[12] {1, 2, 3, 4, 5};

    print(std::cout, array);
    return 0;
}
