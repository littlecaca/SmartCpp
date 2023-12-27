#include <iostream>

template <typename T, size_t Size>
constexpr inline size_t size(const T (&array)[Size]) noexcept
{
    return Size;
}


int main(int argc, char const *argv[])
{
    static int array[12] {21, 5, 54, 23, 43};
    constexpr size_t s = size(array);
    std::cout << "The size of array: " << s << std::endl;

    return 0;
}
