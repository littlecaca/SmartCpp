#include <algorithm>
#include <iostream>
#include <iterator>

template <typename Element_Type, size_t Size>
constexpr Element_Type *begin(Element_Type (&array)[Size]) noexcept
{
    return &array[0];
}

template <typename Element_Type, size_t Size>
constexpr Element_Type *end(Element_Type (&array)[Size]) noexcept
{
    return &array[Size];
}


int main(int argc, char const *argv[])
{
    int array[12] {1, 2, 3, 4, 5, 6, 6};
    std::for_each(begin(array), end(array), [](int iter) { std::cout << iter << " "; });
    std::for_each(std::begin(array), std::end(array), [](int iter) { std::cout << iter << " "; });
    return 0;
}
